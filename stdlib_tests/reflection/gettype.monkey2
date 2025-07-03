#rem Type Detection Test Suite
Author: iDkP from GaragePixel
Since: 2025-07-03

Validates GetType and IsType functions for Variant type system.
Tests string parsing, embedded value detection, and custom type matching.
Using the CastVariant function utility from stdlib.syntax.variantcasts.
#end 

#Import "<stdlib>"

Using stdlib.types..
Using stdlib.reflection
Using stdlib.syntax.variantcasts

Function Main()
	GetTypeUnitTest()
	TestTypeChecking()
End

Function GetTypeUnitTest()
	Print "--- GetType from Variant with value embedded in string"
	Print GetType(CastVariant("2.4"),	True)	'Float
	Print GetType(CastVariant("f2.4"),	True) 	'String
	Print GetType(CastVariant("f2.0"),	True) 	'String
	Print GetType(CastVariant("2.0"),	True) 	'Float
	Print GetType(CastVariant("2"),		True) 	'Int
	Print GetType(CastVariant("True"),	True) 	'Bool
	Print GetType(CastVariant("2"),		True) 	'Int
	
	Print "--- GetType from Variant with any value"
	Print GetType(CastVariant(True)) 			'Bool
	Print GetType(CastVariant(2)) 				'Int
	Print GetType(CastVariant(2.5)) 			'Float
	Print GetType(CastVariant(2.0)) 			'Float
	Print GetType(CastVariant("2")) 			'String
	
	Print "--- GetType from any value embedded in string"
	Print GetType("f2.0")						'String
	Print GetType("f2.5")						'String
	Print GetType("2.0")						'Float
	Print GetType("2")							'Int
	Print GetType("2.4")						'Float
	Print GetType("true")						'Bool
	Print GetType("True")						'Bool
	Print GetType("TRUE")						'Bool
	Print GetType("TrUE")						'Bool
	Print GetType("false")						'Bool
	Print GetType("False")						'Bool
	Print GetType("FALSE")						'Bool
	Print GetType("FaLSE")						'Bool
End 

Class MyCustomClass
	Field name:String
	
	Method New(n:String)
		name = n
	End
End

Class Circle
	Field radius:Float
	
	Method New(r:Float)
		radius = r
	End
End

Function TestTypeChecking:Void()
	
	Local myObj:=New MyCustomClass("test")
	Local circle:=New Circle(5.0)
	
	Local variantObj:=Cast<Variant>(myObj)
	Local variantCircle:=Cast<Variant>(circle)
	
	' Get type references for comparison
	Local myCustomType:=Typeof(myObj)
	Local circleType:=Typeof(circle)
	
	' Exact type checking
	Print "--- Test Exact Type Checking"
	Print IsType(variantObj, myCustomType)		' True
	Print IsType(variantCircle, circleType)		' True
	Print IsType(variantCircle, myCustomType)	' False
	
End
