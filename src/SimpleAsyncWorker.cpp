#include "SimpleAsyncWorker.h"

int fibonacci(int n) {
  if (n < 2) return n;
  return fibonacci(n - 2) + fibonacci(n - 1);
}


SimpleAsyncWorker::SimpleAsyncWorker(Function& callback, int fibRuns)
    : AsyncWorker(callback), fibRuns(fibRuns) {};
int fibResult;
void SimpleAsyncWorker::Execute() { // this runs on separate thread(async)
    fibResult = fibonacci(fibRuns);
};

void SimpleAsyncWorker::OnOK() { // this runs if onExecute did not throw error
    std::string msg = std::to_string(fibResult);
    Callback().Call({Env().Null(), Napi::String::New(Env(), msg)}); // this returns arguments to callback function (err, result) and since there where no errors first argument is null
};


