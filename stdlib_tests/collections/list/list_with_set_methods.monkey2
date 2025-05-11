#Import "<stdlib>"
Using stdlib.collections..

Class List<T> Extension
	
	' We will use a special verbose version of MakeUniqueType, it's the same than the one
	' in List, but with some console outputs for analysis purpose. Since the custom type
	' must has implemented a to:string operator, it can works only on specific custom type
	' so that is why the library version can really works on any custom type 
	' and not this special version.
	' In the test unit, you can uncomment the library version for testing. It's sets by
	' default with the verbose version in this test unit.

	Method MakeUniqueTypeVerbose:List<T>(onPlace:Bool=True) 'Added by iDkP from GaragePixel
		
		' iDkP from GaragePixel
		' 2025-05-11 - Original algorithm
		'
		' Special verbose method for debugging purpose
		' Bonus: Extra code commentaries
		' Note: 
		'	- In this algorithm, head means "read head", that is to say the pointer 
		'	which fixes on the last detected duplicate. 
		'	It's not the head of the list itself, in the jargon of quasicircular lists.
		'	- The verbose version is only for this test (not the library itself), 
		'	because the compiler will write a version for each custom types of the library 
		'	who do not necessarily have an operator To:String declated.
		
		Local currList:= onPlace ? Self Else Copy()
		
		Local count:=currList.Count() '32 bits -> Updated! (we count only one time the number of items)
		If count=1 Return currList 'We don't need to test a list of a single item
		
		Local firstNode:List<T>.Node=currList.FirstNode() 'Normally, the 1st item will be never removed, so we can memoirize it

		If count=2 'The algorithm starts to be meaningful after 2 items
			If firstNode.Value=firstNode.Succ.Value
				firstNode.Succ.Remove()
				Return currList
			Else 
				Return currList
			End 
		End 

		'Global loop
		Local node:=firstNode 'Used to parse the list. Because FirstNode() has a guard we don't want, we call it only one time
		Local nodeItem:=firstNode 'Current treated item
		Local nodeToCompare:=firstNode 'Second item to compare with the current treated item
		Local lastNode:=currList.LastNode() 'memoirize that
		
		'Inner loop
		Local occurance:UInt '32 bits - count the number of duplicates in a list for the on-going treated item
		Local actCount:=count '32 bits - active count, keep track of the number of items
		Local lp:UInt=count+1 '32 bits - loop left, sets on the active count
		Local comps:UInt '32 bits - used for the matching loop
		Local op:UInt '32 bits - used for counting the deletions to perform
		
		'Speed up
		Local lastHead:=lastNode '32 bits - used to stick the head on the last duplicate detected
		Local lastCnt:UInt '32 bits - used to calculate the head from the number of programmed deletions

		Repeat 'accr lp

			occurance=0
			If nodeItem.Value<>Null
				Print "~n ==== curr item: "+nodeItem.Value+" ===="
			Else 
				Print "~n ==== curr item: Null (last loop) ===="
			End 
			nodeToCompare=firstNode
			comps=actCount

			lastCnt=0
			Repeat 'accr nodeToCompare
				
				'we need to compare the node's value, where T could be from any type
				If nodeToCompare.Value=nodeItem.Value
					occurance+=1
					lastHead=nodeToCompare
					lastCnt-=1
					Print "Found match: "+nodeToCompare.Value+" = "+nodeItem.Value+" -> new occurance: "+occurance
				End 
				Print "compared with: "+nodeToCompare.Value+" with occurance: "+occurance
				
				nodeToCompare=nodeToCompare.Succ
				comps-=1
				lastCnt+=1
				
			Until comps=0

			If occurance>1

				Print "  Occurance > 1 ("+occurance+") -> need removing"
				
				'Without the speed up, we jump to the last item of the list:
				'	op=count
				'	node=currList.LastNode() 'loosing the last node mark, we need to update it
				'	Because MakeUniqueType is integrated, we can use instead:
				'	node=_head._pred 'that avoids to check
				'
				'With the speed up, we stick the head to the last duplicate found:
				op=count-lastCnt
				node=lastHead
				
				Print "  -> Head to: "+node.Value+" on the "+op+"th item"

				Repeat

					'same than above, we need to compare the node's value, where T could be from any type
					If node.Value=nodeItem.Value
						Print "  -> Found a match on the "+op+"th item"
						node=node.Pred
						occurance-=1
						Print "  -> Now head over: "+node.Value
						Print "  -> Removed: "+node.Succ.Value+", new occurance: "+occurance
						node.Succ.Remove()
						actCount-=1
						op-=1
						lp-=1
					End 

					node=node.Pred
					op-=1

				Until op=1 Or occurance=1 'Stop without checking the whole list if we know it was the last one

			End 

			nodeItem=nodeItem.Succ

		lp-=1
		Until lp=0

		Return currList
	End
End 

Class CustomItem
	' Special custom type for the verbose MakeUniqueType
	Field _label:String 
	Method New(label:String)
		_label=label
	End 
	Operator To:String() 'Here, the operator
		Return _label
	End 
End 

Class ListAddTests

	Method TestAll()
		Print("===== List Add Operations Unit Tests =====")
		
		TestAppend()
		TestUnion()
		TestIntersect()
		TestDiff()
		TestMakeUnique()
		
		Print("===== All Tests Complete =====")
	End
	
	Method TestAppend()
		Print("~n-------------------------------")
		Print("Testing Append operation...")
		Print("-------------------------------")
		
		Print("~n----------------- Case 1: Non-overlapping lists")
		
		' Case 1: Non-overlapping lists
		Local list1:= New List<String>()
		list1.Add("apple")
		list1.Add("banana")
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("-----------------")
		
		Local list2:= New List<String>()
		list2.Add("cherry")
		list2.Add("date")
		Print "Print List2"
		For Local n:=Eachin list2
			Print n
		Next 
		
		Print("~n----------------- Copy variant")
		
		' Copy variant
		Local result:= list1.Append(list2, False)
		Assert(result.Count() = 4)
		Assert(result.Contains("apple"))
		Assert(result.Contains("banana"))
		Assert(result.Contains("cherry"))
		Assert(result.Contains("date"))
		Print "Print Result"
		For Local n:=Eachin result
			Print n
		Next 
		
		Print("~n----------------- In-place variant")
		
		' In-place variant
		list1.Append(list2, True)
		Assert(list1.Count() = 4)
		Assert(list1.Contains("apple"))
		Assert(list1.Contains("banana"))
		Assert(list1.Contains("cherry"))
		Assert(list1.Contains("date"))
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("~n----------------- Case 2: Overlapping lists")
		
		' Case 2: Overlapping lists
		Local list3:= New List<String>()
		list3.Add("apple")
		list3.Add("banana")
		Print "Print List3"
		For Local n:=Eachin list3
			Print n
		Next 
		
		Print("-----------------")
		
		Local list4:= New List<String>()
		list4.Add("banana")
		list4.Add("cherry")
		Print "Print List4"
		For Local n:=Eachin list4
			Print n
		Next 
		
		Print("-----------------")
		
		result = list3.Append(list4, False)
		Assert(result.Count() = 4)
		Assert(result.Contains("apple"))
		Assert(result.Contains("banana"))
		Assert(result.Contains("banana")) 'expected a second banana!
		Assert(result.Contains("cherry"))
		Print "Print Result"
		For Local n:=Eachin result
			Print n
		Next 
		
		Print("~n-----------------")
		Print("Append tests passed!")
		Print("-----------------")
	End 

	Method TestUnion()
		Print("~n-------------------------------")
		Print("Testing Union operation...")
		Print("-------------------------------")
		
		Print("~n----------------- Case 1: Non-overlapping lists") 'ok
		
		' Case 1: Non-overlapping lists
		Local list1:= New List<String>()
		list1.Add("apple")
		list1.Add("banana")
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("-----------------")
		
		Local list2:= New List<String>()
		list2.Add("cherry")
		list2.Add("date")
		Print "Print List2"
		For Local n:=Eachin list2
			Print n
		Next 
		
		Print("~n----------------- Copy variant")
		
		' Copy variant
		Local result:= list1.Union(list2, False)
		Print "Print Result"
		For Local n:=Eachin result
			Print n
		Next
		Assert(result.Count() = 4)
		Assert(result.Contains("apple"))
		Assert(result.Contains("banana"))
		Assert(result.Contains("cherry"))
		Assert(result.Contains("date"))
		
		Print("~n----------------- In-place variant")
		
		' In-place variant
		list1.Union(list2, True)
		Assert(list1.Count() = 4)
		Assert(list1.Contains("apple"))
		Assert(list1.Contains("banana"))
		Assert(list1.Contains("cherry"))
		Assert(list1.Contains("date"))
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("~n----------------- Case 2: Overlapping lists")
		
		' Case 2: Overlapping lists
		Local list3:= New List<String>()
		list3.Add("apple")
		list3.Add("banana")
		Print "Print List3"
		For Local n:=Eachin list3
			Print n
		Next 
		
		Print("-----------------")
		
		Local list4:= New List<String>()
		list4.Add("banana")
		list4.Add("cherry")
		Print "Print List4"
		For Local n:=Eachin list4
			Print n
		Next 
		
		Print("-----------------")
		
		result = list3.Union(list4, False) 'DOESN'T WORKS
		Print "Print Result"
		For Local n:=Eachin result
			Print n
		Next 
		Assert(result.Count() = 3)
		Assert(result.Contains("apple"))
		Assert(result.Contains("banana"))
		Assert(result.Contains("banana")) 'not expected a second banana!
		Assert(result.Contains("cherry"))

		
		Print("~n-----------------")
		Print("Union tests passed!")
		Print("-----------------")
	End
	
	Method TestIntersect()
		Print("~n-------------------------------")
		Print("Testing IntersectKey operation...")
		Print("-------------------------------")
		
		Print("~n----------------- Case 1: Overlapping lists")
		
		' Case 1: Overlapping lists
		Local list1:= New List<String>()
		list1.Add("apple")
		list1.Add("banana")
		list1.Add("cherry")
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("-----------------")
		
		Local list2:= New List<String>()
		list2.Add("banana")
		list2.Add("cherry")
		list2.Add("date")
		Print "Print List2"
		For Local n:=Eachin list2
			Print n
		Next 
		
		Print("~n----------------- Copy variant")

		' 
		Local result:= list1.Intersect(list2, False)
		Print "Print Result"
		For Local n:=Eachin result 
			Print n
		Next 		
		Assert(result.Count() = 2)
		Assert(Not result.FindNode("apple"))
		Assert(result.FindNode("banana"))
		Assert(result.FindNode("cherry"))
		
		Print("~n----------------- In-place variant")
		
		' In-place variant
		list1.Intersect(list2, True)
		Assert(list1.Count() = 2)
		Assert(Not list1.FindNode("apple"))
		Assert(list1.FindNode("banana"))
		Assert(list1.FindNode("cherry"))
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("~n-----------------")
		Print("IntersectKey tests passed!")
		Print("-----------------")
	
	End

	Method TestDiff()
		Print("~n-------------------------------")
		Print("Testing DiffKey operation...")
		Print("-------------------------------")
		
		Print("----------------- Case 1: Overlapping lists")
		
		' Case 1: Overlapping lists
		Local list1:= New List<String>()
		list1.Add("apple")
		list1.Add("banana")
		list1.Add("cherry")
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("-----------------")
		
		Local list2:= New List<String>()
		list2.Add("banana")
		list2.Add("date")
		Print "Print List2"
		For Local n:=Eachin list2
			Print n
		Next 
		
		Print("~n----------------- Copy variant")
		
		' Copy variant
		Local result:= list1.Diff(list2, False)
		Assert(result.Count() = 2)
		Assert(result.Contains("apple"))
		Assert(Not result.Contains("banana"))
		Assert(result.Contains("cherry"))
		Assert(Not result.Contains("date"))
		Print "Print result"
		For Local n:=Eachin result
			Print n
		Next 
		
		Print("~n----------------- In-place variant")
		
		' In-place variant
		list1.Diff(list2, True)
		Assert(list1.Count() = 2)
		Assert(list1.Contains("apple"))
		Assert(Not list1.Contains("banana"))
		Assert(list1.Contains("cherry"))
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next 
		
		Print("~n-----------------")
		Print("DiffKey tests passed!")
		Print("-----------------")
	End
	
	Method TestMakeUnique()

		Print("~n-------------------------------")
		Print("Testing MakeUnique operation...")
		Print("-------------------------------")
		
		Print("~n----------------- Long list")

		' Long list
		Local list1:= New List<String>()
		list1.Add("apple")
		list1.Add("banana")
		list1.Add("cherry")
		list1.Add("juice")
		list1.Add("date")
		list1.Add("banana")
		list1.Add("banana")
		list1.Add("apple")
		list1.Add("date")
		list1.Add("orange")
		list1.Add("blackberry")
		Print "Print List1"
		For Local n:=Eachin list1
			Print n
		Next
		Local uniqueItemList:=list1.MakeUnique(False)
		'Expected list:
		Assert(uniqueItemList.FindNode("apple"))
		Assert(uniqueItemList.FindNode("banana"))
		Assert(uniqueItemList.FindNode("cherry"))
		Assert(uniqueItemList.FindNode("juice"))
		Assert(uniqueItemList.FindNode("date"))
		Assert(uniqueItemList.FindNode("orange"))
		Assert(uniqueItemList.FindNode("blackberry"))
		Print("~n-----------------")
		Print "List1 after MakeUnique (keep the original order)"
		Print("-----------------")
		For Local n:=Eachin uniqueItemList
			Print n
		Next
		list1.MakeUniqueFast()
'		'Expected list:
		Assert(list1.FindNode("apple"))
		Assert(list1.FindNode("banana"))
		Assert(list1.FindNode("cherry"))
		Assert(list1.FindNode("juice"))
		Assert(list1.FindNode("date"))
		Assert(list1.FindNode("orange"))
		Assert(list1.FindNode("blackberry"))
		Print("~n-----------------")
		Print "List1 after MakeUnique (do not keep the original order)"
		Print("-----------------")
		For Local n:=Eachin list1
			Print n
		Next

		Print("~n----------------- Custom Type list")
		Print("The custom type MakeUnique can threat any custom datatype (object)")
	
		Local banana:=New CustomItem("banana")
		Local date:=New CustomItem("date")
		Local apple:=New CustomItem("apple")
		Local orange:=New CustomItem("orange")
		Local blackberry:=New CustomItem("blackberry")
	
		Local list2:=New List<CustomItem>()
		list2.Add(banana)
		list2.Add(date)
		list2.Add(apple)
		list2.Add(banana)
		list2.Add(banana)
		list2.Add(orange)
		list2.Add(date)
		list2.Add(blackberry)
		list2.Add(blackberry)
		list2.Add(blackberry)
		
		Print("~n-------- list1 before MakeUnique:")
	
		For Local n:=Eachin list2
			Print n
		Next
		
		Print("~n-------- MakeUnique process with custom type in list1:")
		Print("we will use a special verbose version for debugging purpose...")
		list2.MakeUniqueTypeVerbose()
	'	list2.MakeUniqueType()
	
		Print("~n-------- list1 after MakeUnique:")
	
		For Local n:=Eachin list2
			Print n
		Next
		
		Print("~n-----------------")
		Print("MakeUnique tests passed!")
		Print("-----------------")
	End 
End

Function Main()
	Local tests:= New ListAddTests
	tests.TestAll()
End
