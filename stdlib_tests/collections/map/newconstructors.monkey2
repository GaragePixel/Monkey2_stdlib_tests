#Import "<stdlib>"
Using stdlib.collections

Function Main()
		' Prefilled constructor - uniform value for all keys
		Local names:=New String[]("Alice", "Bob", "Charlie")
		Local scores:=New Map<String,Int>(names, 100)
		' Result: scores = { "Alice"=100, "Bob"=100, "Charlie"=100 }	
		Print "scores = "+scores

		' Prefilled map with same value for all keys
		Local keys:=New Int[](100,200,300)
		Local m0:=New Map<Int,Int>(keys, 42)
		' Result: m1 = { "100"=42, 200=42, 300=42 }
		Print "m0 = "+m0

'		' Prefilled map with same value for all keys
		Local keys0:=New String[]("foo","bar","baz")
		Local m1:=New Map<String,Int>(keys0, 42)
'		' Result: m1 = { "foo"=42, "bar"=42, "baz"=42 }
		Print "m1 = "+m1

		' Synchronized arrays constructor - paired key-value mapping
		Local players:=New String[]("Alice", "Bob", "Charlie")
		Local points:=New Int[](95, 87, 92)
		Local rankings:=New Map<String,Int>(players, points)
		' Result: rankings = { "Alice"=>95, "Bob"=>87, "Charlie"=>92 }
		Print "rankings = "+rankings

'		' Prefilled map with keys and values from arrays (values shorter, last value repeated)
		Local keys2:=New String[]("a","b","c","d")
		Local vals2:=New Int[](100,200)
		Local m2:=New Map<String,Int>(keys2, vals2)
		' Result: m2 = { "a"=100, "b"=200, "c"=200, "d"=200 }
		Print "m2 = "+m2

		' Prefilled map with keys and values from arrays (keys shorter, extra values ignored)
		Local keys3:=New String[]("k1","k2")
		Local vals3:=New Int[](7,8,9)
		Local m3:=New Map<String,Int>(keys3, vals3)
		' Result: m3 = { "k1"=7, "k2"=8 }
		Print "m3 = "+m3
		
		' Indexed constructor - sequential integer keys
		Local items:=New String[]("sword", "shield", "potion")
		Local inventory:=New Map<Int,String>(items)
		' Result: inventory = { 0="sword", 1="shield", 2="potion" }
		Print "inventory = "+inventory

		' Indexed map with values from array (keys auto-incrementing Int)
		Local vals4:=New Int[](77,88,99)
		Local m4:=New Map<Int,Int>(vals4)
		' Result: m4 = { 0=77, 1=88, 2=99 }
		Print "m4 = "+m4
End 