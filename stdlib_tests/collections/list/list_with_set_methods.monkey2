Namespace ListStressTestUnit

#rem
	List Set Operations - stdlib extension 1.0.0
	Implementation: iDkP from GaragePixel
	Date: 2025-05-12 Aida: 4.0

	Set (math) operations for the standard List<T> class, providing efficient collection manipulation
	with both in-place and copy operations. The implementation focuses on ultra performance.

	These extension methods bring set theory operations to Monkey2's stdlib collections:

		- Append - Combines two lists preserving all elements including duplicates (fastest)
		- Union - Merges two lists removing duplicates (set union operation)
		- Intersect - Creates list containing only elements present in both input lists
		- Diff - Creates list containing elements from first list not present in second
		- Dedup - Removes duplicate elements from a single list

	Performance characteristics:

		- Append: Ultra-fast pointer manipulation (25-50M elements/second)
		- Union: Efficient hash-based deduplication (600K-1.4M elements/second)
		- Intersect: Fast set intersection (600K-1.6M elements/second)
		- Diff: Optimized difference operation (500K-1.1M elements/second)
		- Dedup: Compute 100K elements in 79-148ms (25M-50M elements/second)

	All operations maintain linear complexity (O(n)) regardless of collection size by
	utilizing hash-based lookups rather than naive nested traversals.

	Suggested use cases:
		- Game development: Entity management, feature detection
		- Data processing: Record merging, filtering, deduplication
		- Search systems: Result combination, intersection filtering
		- Access control: Permission calculation, exclusion filtering
#end

#Import "<stdlib>"

Using stdlib.collections..
Using stdlib.system.time..
Using stdlib.math.random..

'Note: if you want test with Wonkey, comment the #Import command and the Using and uncomment these following lines:

'#Import "<std>"
'Using std..

Class List<T> Extension

	Method Dedup_oldImplementation:List<T>(onPlace:Bool=True)
		
		' iDkP:
		'	Was my 1st Depublication's implementation, 
		'	it shows how new capability to cast a list 
		'	into a map implicitaly as map=list, or map=list.ToMap()
		'	according the type of casting (list's items as key or value).
		'	The "normal version" is explicite, it converts the list into
		'	map's values. The implicite version is more tendious, it converts
		'	the list's values into map's key.
		'	The Dedup in the library do not use the map casting, it creates
		'	a map and iterate directly over some guards, making it 1.12x faster.
		'	This version compute 670,000 elements per seconds while the
		'	library version computes 741,000 per second.

		Local currList:= onPlace ? Self Else Copy()
		
		Local atLeastTwo:=currList.HasOneOrTwo
		If atLeastTwo=1 Return currList
		
		Local firstNode:List<T>.Node=currList.FirstNode

		If atLeastTwo=2
			If firstNode.Value=firstNode.Succ.Value
				firstNode.Succ.Remove()
				Return currList
			Else 
				Return currList
			End 
		End 

		Local map:Map<T,UInt>
		map=currList 
		currList.Clear()
		For Local item:=Eachin map 
			currList.Add(item.Key)
		End 
		
		Return currList
	End
End 

Class CustomItem
	' Special custom type for the tests
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
		
		Print("~n===============================")
		Print("Testing Union operation...")
		Print("===============================")
		
		TestAppend()
		TestUnion()
		TestIntersect()
		TestDiff()
		TestDedup()
		
		TestStressDedup()
		StressTestAppend()
		StressTestUnion()
		StressTestIntersect()
		StressTestDiff()
		
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
		
		result = list3.Union(list4, False)
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
		Print("Testing Intersect operation...")
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
		Local result:=list2.Intersect(list1, False)
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
		Print("Intersect tests passed!")
		Print("-----------------")
	
	End

	Method TestDiff()
		Print("~n-------------------------------")
		Print("Testing Diff operation...")
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
		Print("Diff tests passed!")
		Print("-----------------")
	End
	
	Method TestDedup()

		Print("~n-------------------------------")
		Print("Testing Dedup operation...")
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
		'list1.Dedup_oldImplementation(False)
		list1.Dedup()
		Print("~n-----------------")
		Print("List1 after Dedup")
		Print("-----------------")
		For Local n:=Eachin list1
			Print n
		Next
		'Expected list:
		Assert(list1.FindNode("apple"))
		Assert(list1.FindNode("banana"))
		Assert(list1.FindNode("cherry"))
		Assert(list1.FindNode("juice"))
		Assert(list1.FindNode("date"))
		Assert(list1.FindNode("orange"))
		Assert(list1.FindNode("blackberry"))

		Print("~n----------------- Custom Type list")
	
		Local banana:=New CustomItem("banana")
		Local date:=New CustomItem("date")
		Local apple:=New CustomItem("apple")
		Local orange:=New CustomItem("orange")
		Local blackberry:=New CustomItem("blackberry")
	
		Local list3:=New List<CustomItem>()
		list3.Add(banana)
		list3.Add(date)
		list3.Add(apple)
		list3.Add(banana)
		list3.Add(banana)
		list3.Add(orange)
		list3.Add(date)
		list3.Add(blackberry)
		list3.Add(blackberry)
		list3.Add(blackberry)
		
		Print("~n-------- list1 before Dedup")
	
		For Local n:=Eachin list3
			Print n
		Next
		
		Print("~n-------- Dedup process with custom type in list1:")
		list3.Dedup()
	
		Print("~n-------- list1 after Dedup:")
	
		For Local n:=Eachin list3
			Print n
		Next
		
		Print("~n-----------------")
		Print("Dedup tests passed!")
		Print("-----------------")
	End 

	' ===================================================== Stress Tests

	Method TestStressDedup()
		Print("~n===== Stress Testing =====")
		
		Print("~n===== Stress Testing Dedup =====")
		
		Local sizes:Int[] = New Int[](1000, 10000, 100000)
		Local dupeRates:Float[] = New Float[](0.25, 0.5, 0.75)
		
		For Local size:= Eachin sizes
			For Local dupeRate:= Eachin dupeRates
				Local list:= Bencher.GenerateDuplicateStrings(size, dupeRate)
				Local count:Int = list.Count()
				
				Local startTime:Int = Millisecs()
				list.Dedup()
				'list.Dedup_oldImplementation()
				Local duration:Int = Millisecs() - startTime
				
				Print("Dedup: size=" + size + ", dupe=" + dupeRate + ", time=" + duration + "ms, reduction=" + (count - list.Count()))
			End
		End
		Print("===== Dedup Stress Test Complete =====")
	End

	' Stress test for Append operation
	Method StressTestAppend:Void()
		Print("~n===== Stress Testing Append =====")
		
		' Test with various list sizes and duplication rates
		For Local size:= EachIn New Int[](1000, 10000, 100000)
			For Local dupeRate:= EachIn New Float[](0.25, 0.5, 0.75)
				Local list1:= Bencher.GenerateDuplicateStrings(size, dupeRate)
				Local list2:= Bencher.GenerateDuplicateStrings(size/10, dupeRate) ' Smaller second list

				Local startTime:Int = Millisecs()
				list1.Append(list2, True)		
				Local duration:Int = Millisecs() - startTime

				Local throughput:=Bencher.CalculateElementsPerSecond(size, duration)
				Print("Append: size=" + size + ", dupe=" + dupeRate + ", time=" + duration + "ms, throughput=" + Bencher.FormatThroughput(throughput, True))
			Next
		Next
		
		Print("===== Append Stress Test Complete =====")
	End
	
	' Stress test for Union operation
	Method StressTestUnion:Void()
		Print("~n===== Stress Testing Union =====")
		
		' Test with various list sizes and duplication rates
		For Local size:= EachIn New Int[](1000, 10000, 100000)
			For Local dupeRate:= EachIn New Float[](0.25, 0.5, 0.75)
				Local list1:= Bencher.GenerateDuplicateStrings(size, dupeRate)
				Local list2:= Bencher.GenerateDuplicateStrings(size/10, dupeRate) ' Smaller second list

				Local startTime:Int = Millisecs()
				list1.Union(list2, True)
				Local duration:Int = Millisecs() - startTime	

				Local throughput:=Bencher.CalculateElementsPerSecond(size, duration)
				Print("Union: size=" + size + ", dupe=" + dupeRate + ", time=" + duration + "ms, throughput=" + Bencher.FormatThroughput(throughput, True))
			Next
		Next
		
		Print("===== Union Stress Test Complete =====")
	End
	
	' Stress test for Intersect operation
	Method StressTestIntersect:Void()
		Print("~n===== Stress Testing Intersect =====")
		
		' Test with various list sizes and duplication rates
		For Local size:= EachIn New Int[](1000, 10000, 100000)
			For Local dupeRate:= EachIn New Float[](0.25, 0.5, 0.75)
				Local list1:= Bencher.GenerateDuplicateStrings(size, dupeRate)
				' Create second list with some overlap for meaningful intersection
				Local list2:= New List<String>
				For Local i:=0 Until size/5
					list2.AddLast("Item"+String(i Mod (size/10)))
				Next
				
				Local startTime:Int = Millisecs()
				list1.Intersect(list2, True)
				Local duration:Int = Millisecs() - startTime

				Local throughput:=Bencher.CalculateElementsPerSecond(size, duration)
				Print("Intersect: size=" + size + ", dupe=" + dupeRate + ", time=" + duration + "ms, throughput=" + Bencher.FormatThroughput(throughput, True))			
			Next
		Next
		
		Print("===== Intersect Stress Test Complete =====")
	End
	
	' Stress test for Diff operation
	Method StressTestDiff:Void()
		Print("~n===== Stress Testing Diff =====")
		
		' Test with various list sizes and duplication rates
		For Local size:= EachIn New Int[](1000, 10000, 100000)
			For Local dupeRate:= EachIn New Float[](0.25, 0.5, 0.75)
				Local list1:= Bencher.GenerateDuplicateStrings(size, dupeRate)
				' Create second list with some overlap
				Local list2:= New List<String>
				For Local i:=0 Until size/5
					list2.AddLast("Item"+String(i Mod (size/10)))
				Next

				Local startTime:Int = Millisecs()
				list1.Diff(list2, True)
				Local duration:Int = Millisecs() - startTime
				
				Local throughput:=Bencher.CalculateElementsPerSecond(size, duration)
				Print("Diff: size=" + size + ", dupe=" + dupeRate + ", time=" + duration + "ms, throughput=" + Bencher.FormatThroughput(throughput, True))				
			Next
		Next
		
		Print("===== Diff Stress Test Complete =====")
	End

End

Class Bencher 
	
	Function CalculateElementsPerSecond:Float(elementCount:Int, timeMs:Int)
		
		' Guard against division by zero
		If timeMs = 0 Then Return 0.0
		
		' Convert milliseconds to seconds for calculation
		Local timeSeconds:Float = timeMs / 1000.0
		
		' Calculate elements per second
		Local elementsPerSecond:Float = elementCount / timeSeconds
		
		Return elementsPerSecond
	End
	
	Function FormatThroughput:String(elementsPerSecond:Float, roundToThousands:Bool = True)
		
		If roundToThousands
			' Round to nearest thousand
			Local rounded:Int = Int(elementsPerSecond / 1000.0) * 1000
			Return rounded + " elements/second"
		Else
			' Format with comma separators
			Return Int(elementsPerSecond) + " elements/second" 
		End
	End
	
	Function GenerateDuplicateStrings:List<String>(size:Int, dupeRate:Float)
		
		' Create list with controlled duplication rate
		Local list:= New List<String>
		
		' Calculate how many unique values we need
		Local uniqueCount:Int = Int(size * (1.0 - dupeRate))
		If uniqueCount < 1 Then uniqueCount = 1
		
		' Generate unique values
		For Local i:Int = 0 Until uniqueCount
			list.AddLast("UniqueValue" + i)
		End
		
		' Fill remaining slots with duplicates
		While list.Count() < size
			' Pick random existing item to duplicate
			Local index:Int = Rnd(1, uniqueCount)
			list.AddLast(index)
		Wend
		
		Return list
	End
End 

Function Main()
	Local tests:= New ListAddTests
	tests.TestAll()
End
