
'Test about Template-constrained overload (TCO)
'iDkP from GaragePixel
'Since 2025-07-09

#Import "<stdlib>"

Using stdlib.types..
Using stdlib.syntax..
Using stdlib.aliases.prefixes
Using stdlib.math.stats

Class T1
End 
Class T2
End 
Class T3
End 

' different argument types

Function F<P>:Int(t:T1) Where P=_p0_
	Return Null
End

Function F<P>:Int(t:T2) Where P=_p0_
	Return Null
End

' different returned types with the same prefix (do not works)

'Function F<P>:Float(t:T1) Where P=_p0_
'	Return Null
'End
'
'Function F<P>:Float(t:T2) Where P=_p0_
	'Return Null
'End

' different returned types with different prefix

Function F<P>:Int(t:T1) Where P=_p1_
	Return Null
End

Function F<P>:Int(t:T2) Where P=_p1_
	Return Null
End

Function F<P>:Float(t:T1) Where P=_p2_
	Return Null
End

Function F<P>:Float(t:T2) Where P=_p2_
	Return Null
End

Function F<P>:Double(t:T2) Where P=_p3_
	Return Null
End

Function F<P>:Double(t:T3) Where P=_p3_
	Return Null
End

Function F<P,C,T>:T(t:C) Where P=_p1_
	Return Cast<T>(0)
End

Function F<P,C,T>:T(t:C) Where P=_p2_
	Return Cast<T>(0)
End

Function F<P,C,T>:T(t1:C,t2:Int) Where P=_p2_
	Return Cast<T>(0)
End

Function F<P,C,T>:T(t1:C) Where P=_p2_ And T=Float
	Return Cast<T>(0)
End

'Templating:

Function Ft<R>:R(t1:T1) 'templating
	Return F<_p1_,T1,R>(t1)
End 

Function Ft<T1>:Float(t1:T1) 'templating
	Return F<_p1_,T1,Float>(t1)
End 

Function Ft<T1>:Float(t1:T1,t2:Int) 'templating with overloaded argument
	Return F<_p1_,T1,Float>(t1)
End 

Function Ft<T1>:Float(t1:T1,t2:Int,t3:Float,t4:String="") 'templating with optional overloaded argument
	Return F<_p1_,T1,Float>(t1)
End 

Function Main()
	Local v01:Int=F<_p0_>(New T1) 		'prefix, 	 	arg type, 	 		return type, 			success
	Local v02:Int=F<_p0_>(New T2) 		'same prefix, 	differ arg type, 	same return type, 		success
'	Local v03:Float=F<_p0_>(New T1) 	'same prefix, 	same arg type, 		differ1 return type, 	fails
'	Local v04:Float=F<_p0_>(New T2) 	'same prefix, 	same arg type, 		differ1 return type, 	fails
	Local v05:Int=F<_p1_>(New T1)		'differ prefix,	same arg type, 		same return type, 		success
	Local v06:Int=F<_p1_>(New T2)		'differ prefix,	differ arg type, 	same return type, 		success
	Local v07:Float=F<_p2_>(New T1)		'differ prefix,	same arg type,		differ2 Return type, 	success
	Local v08:Float=F<_p2_>(New T2)		'differ prefix,	differ arg type,	differ2 Return type, 	success
	Local v09:Double=F<_p3_>(New T2)	'differ prefix,	differ arg type,	differ3 Return type, 	success
	Local v10:Double=F<_p3_>(New T3)	'differ prefix,	differ arg type,	differ3 Return type, 	success
	Local v11:Byte=F<_p3_>(New T3)		'differ prefix,	differ arg type,	differ3 Return type, 	success
	
	Local v12:=F<_p1_,T3,Byte>(New T3)	'differ prefix,	templated arg type,			differ3 Return type, 	success
	Local v13:=F<_p1_,T1,Int>(New T1)	'differ prefix,	differ templated arg type,	differ3 Return type, 	success
	Local v14:=F<_p2_,T3,Byte>(New T3)	'differ prefix,	differ templated arg type,	differ3 Return type, 	success
	Local v15:=F<_p2_,T1,Int>(New T1)	'differ prefix,	differ templated arg type,	differ3 Return type, 	success
	Local v16:=F<_p2_,T1,Int>(New T1,0)	'differ prefix,	differ templated arg type,	differ3 Return type, 	success

	Local v17:=Ft<Int>(New T1)			'Templating, explicit return type
	Local v18:=Ft(New T1,0)				'Templating, implicit return type
	Local v19:=Ft(New T1,0,0.0)			'Templating, explicit return type with overload
	Local v20:=Ft(New T1,0,0.0,"")		'Templating, explicit return type with overload and optional overload

	'Usage examples:

    Local bools:=New Stack<Bool>(New Bool[](True,True,False))
    Print "Avr<_pFastPct>: "+Avr<_pFastPct_>(bools)+"%"
    Print "Avr<_pPct_>: "+Avr<_pPct_>(bools)+"%"
    Print "Avr<_pFract_>: "+Avr<_pFract_>(bools)    
    Print "Truth (TCO): "+Truth<_pTruth_>(bools) 'output 2
    Print "Untruth (TCO): "+Truth<_pUntruth_>(bools) 'output 1
    Print "Truth (uses preset overload): "+Truth(bools) 'output 2
    Print "Truth (explicitly overloaded): "+Truth(bools,False) '<- default: deactivated 'output 2
    Print "Untruth (explicitly overloaded): "+Truth(bools,True) '<- untruth activated 'output 1    

	'All Test (all is a function who returns True is all instances exists in a collection)

    Print "All (contains a false value): "+All(bools) 'False
    bools=New Stack<Bool>(New Bool[](True,True))
    Print "All (contains only true values): "+All(bools) 'True
    bools=New Stack<Bool>(New Bool[](True,True,Null))
	Print "All: (contains a null value): "+All(bools) 'False
    Local stackT1:=New Stack<T1>(New T1[](New T1(),New T1(), New T1()))
    Print "All stackT1 (contains only T1 refs): "+All(stackT1) 'True
    stackT1=New Stack<T1>(New T1[](New T1(),New T1(), New T1(), Null))
    Print "All stackT1: (contains a null value): "+All(stackT1) 'False
End
