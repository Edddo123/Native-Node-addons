#pragma once
#include <napi.h>
using namespace Napi;

class SimpleAsyncWorker : public AsyncWorker {
    
    public:
        SimpleAsyncWorker(Function& callback, int fibRuns);
        virtual ~SimpleAsyncWorker() {};

        void Execute();
        void OnOK();
    private:
        int fibRuns;
        int fibResult;
};