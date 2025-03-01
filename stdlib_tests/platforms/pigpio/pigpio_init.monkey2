#Import "<stdlib>"

Using stdlib.platforms.raspberry..

#rem

	You need administrator rights to run this program:

		sudo ./pigpio_init

		Output:
			pigpio version: 78
			pigpio successfully initialized. version = 78

	Without admin rights:

		./pigpio_init

		Output:
			pigpio version: 78
			$Date$ initCheckPermitted: 
			+---------------------------------------------------------+
			|Sorry, you don't have permission to run this program.    |
			|Try running as root, e.g. precede the command with sudo. |
			+---------------------------------------------------------+

#end
Function Main()
	Print "pigpio version: " + PIGPIO_VERSION
	
	Local version := gpioInitialise()
	If version < 0
		Print "error: pigpio initialization failed"
		Return
	Endif
	
	Print "pigpio successfully initialized. version = " + version
	
	gpioTerminate()
End
