#Requires AutoHotkey v2.0
; Potplayer 长按倍速播放
#HotIf WinActive("ahk_class PotPlayer64 ahk_exe PotPlayerMini64.exe")
Right::     ; 模仿B站长按快进功能：长按0.3秒方向右键进行倍速播放，松开时恢复
{
    if !(KeyWait("Right", "T0.3")) { ; 按下按键持续0.3s
        Send("cccccccccccccccccccc") ; 加速x3播放，每个c表示+0.1x，可以自行修改c的数量
        ToolTip(">>>")  ; 脚本执行的提示符
        KeyWait("Right") ;松开按键
        Send("z") ; 播放速度复原
        ToolTip("")
    }
    else {
        Send("{Right}")  ; 如果按键按下未持续0.3s，则触发Potplayer原始快捷键
    }
    return
}