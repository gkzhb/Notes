
class StateWorker() {

  internal fun doNext(state: UserState) = state.checkState(this)

}

interface UserStatus {

  fun checkState(worker: StateWorker)

}

class OwnState:UserStatus{

  override fun checkState(worker: StateWorker) {

    if (!isOwn()){

      worker.doNext(CameraPemissionState())

    }else{

      gotoPayOwn()

    }

  }

}

class DepositState:UserStatus{

  override fun checkState(worker: StateWorker) {

    if(hasDeposit()){

      worker.doNext(RegesterState())

    }else{

      gotoPayDeposit()

    }

  }

}

class RegesterState :UserStatus{

  override fun checkState(worker: StateWorker) {

    if(isRegisterDone()){

      worker.doNext(RegesterState())

    }else{

      gotoRegister()

    }

  }

}

class LoginState:UserStatus{

  override fun checkState(worker: StateWorker) {

     if(isLogin()){

       worker.doNext(RegesterState())

    }else{

      gotoLogin()

    }

  }
