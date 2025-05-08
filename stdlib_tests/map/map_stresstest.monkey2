'Map Stress Test with key as string
'iDkP from GaragePixel
'2025-05-08

#Import "<stdlib>"
Using stdlib.collections
Using stdlib.system.time
Using stdlib.math.random

Function Chr:String(charCode:Int) 
	' Convert an integer character code to a single-character string 
	' Used for binary/character conversions in hash processing 
	Local result:String
	
	' Directly append to empty string using standard ASCII value
	' This is the idiomatic way to create a character from a code in Monkey2
	result += String.FromChar(charCode)

	Return result
End 

Function RandomWord:String(minlength:UInt, maxlength:UInt)
	Local nbCharacter:Int = Rnd(minlength,maxlength)
	Local set:String="abcdefghijklmnopqrstuvwxyz123456789 "
	Local c:Int
	Local result:String
	For Local n:=0 Until nbCharacter
		c=Rnd(0,set.Length-1)
		result+=Chr(set[c])
	End
	Return result
End

Function Main()
	'
	'Expected results:
	'
	'Retrieval of 1000000 items 255 characters by alphanumerical+space word by keys:
	'Time: 518 ms
	'	Rate: 1'930'501 items/second
	'
	'Retrieval of 1000000 items 15-25 characters by alphanumerical+space word by keys:
	'  Time: 153 ms
	'  Rate: 6'535'947 items/second
	'
	Local dictionary:=New Map<String,Int>
	Local words:=New Stack<String>()

	'Create a list of words randomly composed from an alphanumerical set
	For Local n:=0 Until 30
		words.Add(RandomWord(15 ,25)) '15-25 characters
	Next 

	'Mem the word's list's length
	Local wordsLength:=words.Length-1
	
	'Add the words linearly in the map as key and set the value sequencially
	For Local w:Int=0 Until wordsLength
		dictionary.Add(words[w],w)
	Next 
	
	'Declare some loop related foobars
	Local idx:Int 
	Local word:String
	
	'Try to get the stored values in the dictionary searching by word
	'in the natural order (expected output: 1, 2, 3, 4... )
	For Local n:Int=0 Until wordsLength
		
		'Choosen index in natural order
		idx=n
		
		'Retrieve the word by index and store it
		word=words[idx]
		
		'Search the key as word in the dictionary and print its value
		Print(dictionary.Get(word))
	Next 

	'Try to get the stored values in the dictionary searching by word
	'in a randomized order.
	'Expected output: some index values until 100.
	For Local n:Int=0 Until 100
'		
		'Choose a word index
		idx=Rnd(0,wordsLength)
		
		'Retrieve the word by index and store it
		word=words[idx]
		
		'Search the key as word in the dictionary and print its value
		Print(dictionary.Get(word))
	Next 

	'Stress test: 1000000 gets, searching by key as word
	For Local nbTest:Int=0 Until 4'tests
		
		Local ITEM_COUNT:=1000000
		Local startTime:Int = Millisecs()
		
		For Local n:Int=0 Until ITEM_COUNT
	'		
			'Choose a word index
			idx=Rnd(0,wordsLength)
			
			'Retrieve the word by index and store it
			word=words[idx]
			
			'Search the key as word in the dictionary (silently)
			dictionary.Get(word)
		Next 
	
		'Output
		Local lookupTime:Int = Millisecs() - startTime
		Local lookupRate:Float = ITEM_COUNT / (lookupTime / 1000.0)
		Print("~n--------------------------------------------------")
		Print("Map Implementation Stress Test number: "+nbTest)
		Print("--------------------------------------------------")
		Print("Retrieval of " + ITEM_COUNT + " items:")
		Print("  Time: " + lookupTime + " ms")
		Print("  Rate: " + Int(lookupRate) + " items/second")
		Print("~n--------------------------------------------------")
	End
End 
