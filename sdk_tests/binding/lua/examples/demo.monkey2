#Import "<stdlib>"
#Import "<sdk_mojo>"

'Original demo by Shane Woolcock, refactoring by iDkP

Using stdlib.plugins.libc
Using sdk.binding.lua..
Using sdk_mojo..

Const DEMO_FILENAME:String = "modules/sdk/binding/mx2lua-master/examples/assets/demo.lua"

Function Main()
    New AppInstance
    New DemoApp
    App.Run()
End

Class DemoApp Extends Window
    Field state:LuaState
    Field ent:Entity = New Entity

    Method New()
        state = LuaState.NewState()
        state.DoFile(DEMO_FILENAME)
    End

    Method OnRender(canvas:Canvas) Override
        App.RequestRender()
        If Keyboard.KeyHit(Key.Space) Then
            Print "Reloading script..."
            state.DoFile(DEMO_FILENAME)
        End
        ent.Update(state)
        ent.Draw(canvas)
        canvas.DrawText("Press Space to reload script", 0, 0)
    End
End

Class Entity Implements LuaObject
    Field x:Float
    Field y:Float

    Method __index:Int(L:lua_State Ptr)
        Local state := New LuaState(L)
        Local name:String = state.CheckString(2)
        Select name
            Case "x"
                state.PushNumber(x)
                Return 1
            Case "y"
                state.PushNumber(y)
                Return 1
            Case "Test"
                state.PushMethodCall(Self, "Test")
                Return 1
        End
        Return 0
    End

    Method __newindex:Int(L:lua_State Ptr)
        Local state := New LuaState(L)
        Local name:String = state.CheckString(2)
        Select name
            Case "x"
                x = state.CheckNumber(3)
            Case "y"
                y = state.CheckNumber(3)
        End
        Return 0
    End

    Method __methodcall:Int(L:lua_State Ptr)
        Local state := New LuaState(L)
        Local name:String = state.CheckString(state.UpValueIndex(2))
        Select name
            Case "Test"
                Test()
        End
        Return 0
    End

    Method Test:Void()
        Print "Called test for entity with x, y = " + x + ", " + y
    End

    Method Update:Void(state:LuaState)
        state.GetGlobal("update")
        state.PushObject(Self)
        If state.PCall(1, 0, 0) Then
            Print(state.ToString(-1))
        End
    End

    Method Draw:Void(canvas:Canvas)
        canvas.PushMatrix()
        canvas.Translate(x, y)
        canvas.DrawRect(-10, -10, 20, 20)
        canvas.PopMatrix()
    End
End