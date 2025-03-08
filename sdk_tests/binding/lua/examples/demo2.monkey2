#Import "<stdlib>"
#Import "<sdk>"

'iDkP for GaragePixel

Using stdlib.plugins.libc..
Using stdlib.stringio
Using sdk.binding.lua..

Alias lua:sdk.binding.lua

Function Main()
	
    ' Create a new Lua state using the LuaState wrapper class
    Local luaState:lua.api.LuaState = lua.api.LuaState.NewState()

    ' Define a simple Lua script
    Local script:String = "
        print('Hello from Lua!')
        function add(a, b)
            return a + b
        end
        local result = add(3, 4)
        print('3 + 4 = ' .. result)
    "

    ' Load and run the Lua script
    If luaState.LoadString(script) <> LUA_OK Then
        ' Print the error message
        Local errorMsg:String = luaState.ToString(-1)
        Print "Error loading Lua script: " + errorMsg
        Return
    End If

    If luaState.PCall(0, LUA_MULTRET, 0) <> LUA_OK Then
        ' Print the error message
        Local errorMsg:String = luaState.ToString(-1)
        Print "Error running Lua script: " + errorMsg
        Return
    End If

    ' Close the Lua state
    luaState.Close()
End Function
