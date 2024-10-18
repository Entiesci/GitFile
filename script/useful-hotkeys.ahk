; 一些有趣的快捷键
; 禁用大写锁定
; 大写锁定+JKLI 为  方向键
; ctrl+左右     为  home/end


^Right::{
    Send("{End}")
    return
}

^Left::{
    Send("{Home}")
    return
}

^+Right::{
    Send("+{End}")
    return
}

^+Left::{
    Send("+{Home}")
    return
}

SetCapsLockState "AlwaysOff" ; 禁用CapsLock的大写锁定功能

CapsLock & l::{
    Send("{Right}")
}

CapsLock & j::{
    Send("{Left}")
}

CapsLock & i::{
    Send("{Up}")
}

CapsLock & k::{
    Send("{Down}")
}

CapsLock & o::{
    Send("{Backspace}")
}



