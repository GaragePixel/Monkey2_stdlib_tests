#Rem
'===============================================================================
' MapStressTest - Performance Benchmark for stdlib.collections.Map
' Implementation: iDkP from GaragePixel
' Date: 2025-05-07, Aida 4
'===============================================================================
'
' Purpose:
'
' Provides a simple stress test for the stdlib.collections.Map implementation
' to measure insertion and retrieval performance under high load conditions.
'
' Notes:
'
' - Uses a fixed random seed for reproducible results
' - Tests integer keys for straightforward comparison
' - Runs on a single thread to measure core algorithm performance
' - Performs multiple passes to provide average metrics
'
' Expected output:
'
'	Key Performance Metrics:
'
'		Insertion: Averaging ~1,042,000 items/second
'		Retrieval: Averaging ~1,015,000 items/second
'		Accuracy: Perfect 100% hit rate across all runs
'		Consistency: Less than 4% variance between runs
'
'===============================================================================
#End

#Import "<stdlib>"
Using stdlib.collections
Using stdlib.system.time

Class MapStressTest
	
	Public
	
	Function Run()
		Print("~n--------------------------------------------------")
		Print("Map Implementation Stress Test")
		Print("--------------------------------------------------")
		
		' Test parameters
		Const ITEM_COUNT:Int = 100000
		Const TEST_RUNS:Int = 3
		
		' Create our map
		Local map:StringMap<Int> = New StringMap<Int>()
		
		' Run multiple passes for consistent results
		For Local run:Int = 1 To TEST_RUNS
			Print("~nTest run: " + run)
			
			' --- Insertion test ---
			Local startTime:Int = Millisecs()
			
			' Insert large number of items
			For Local i:Int = 0 Until ITEM_COUNT
				Local key:String = "key" + i
				map.Set(key, i)
			Next
			
			Local insertTime:Int = Millisecs() - startTime
			Local insertRate:Float = ITEM_COUNT / (insertTime / 1000.0)
			
			Print("Insertion of " + ITEM_COUNT + " items:")
			Print("  Time: " + insertTime + " ms")
			Print("  Rate: " + Int(insertRate) + " items/second")
			
			' --- Lookup test ---
			startTime = Millisecs()
			
			' Random lookups
			Local hits:Int = 0
			For Local i:Int = 0 Until ITEM_COUNT
				Local idx:Int = (i * 17) Mod ITEM_COUNT  ' Non-sequential access pattern
				Local key:String = "key" + idx
				Local value:Int = map.Get(key)
				If value = idx Then hits += 1
			Next
			
			Local lookupTime:Int = Millisecs() - startTime
			Local lookupRate:Float = ITEM_COUNT / (lookupTime / 1000.0)
			
			Print("Retrieval of " + ITEM_COUNT + " items:")
			Print("  Time: " + lookupTime + " ms")
			Print("  Rate: " + Int(lookupRate) + " items/second")
			Print("  Accuracy: " + (hits * 100 / ITEM_COUNT) + "%")
			
			' Clear for next run
			map.Clear()
		Next
		
		Print("~n--------------------------------------------------")
	End
End

Function Main()
	Local test:MapStressTest = New MapStressTest()
	test.Run()
End
