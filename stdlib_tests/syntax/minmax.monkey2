#Import "<stdlib>"
	
Using stdlib.syntax..

Function Main()
	
	'--- min/max test unit:
	
	Local a_int:Int=10
	Local b_float:Float=10.5
	Local c_double:Double=100.5
	Local a_ubyte:UByte=255

	Print Max(11,22)
	Print Min(11,22)
'	
	Local r1:=Max(b_float,a_int)
	Print r1'10.5
	Print Min(a_int,b_float)'10
	Local r2:=Min(Varptr(a_int),Varptr(b_float))
	Print r2'10
	Print Max(Varptr(a_int),Varptr(b_float))'10
'	
	Local r3:=Min(Varptr(a_int),Varptr(b_float),Varptr(a_ubyte))
	Print r3'10
	Print Max(Varptr(a_int),Varptr(b_float),Varptr(a_ubyte))'255
	
End 
