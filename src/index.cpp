#include "SimpleAsyncWorker.h"
#include <napi.h>
#include <string>

void fibAsync(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    int fibRuns = info[0].As<Number>();
    Function callback = info[1].As<Function>();
    SimpleAsyncWorker* asyncWorker = new SimpleAsyncWorker(callback, fibRuns);
    asyncWorker->Queue(); // this launches Execute function
}


Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "fibAsync"), Napi::Function::New(env, fibAsync));

    return exports;
}

NODE_API_MODULE(asyncFib, Init);