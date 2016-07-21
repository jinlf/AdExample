//
//  future_detail.cpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#include "future_detail.hpp"
namespace firebase {
    
    /// Increment the reference count on handle's asynchronous call.
    /// Called when the Future is copied.
    
    void FutureDetail::ReferenceFuture(FutureHandle handle) {
        mCount++;
    }
    
    /// Decrement the reference count on handle's asynchronous call.
    /// Called when the Future is destroyed or moved.
    /// If the reference count drops to zero, the asynchronous call can be
    /// forgotten.
    void FutureDetail::ReleaseFuture(FutureHandle handle) {
        mCount--;
        if (mCount == 0) {
            delete (FutureObject *)handle;
        }
    }
    
    /// Return the status of the asynchronous call.
    FutureStatus FutureDetail::GetFutureStatus(FutureHandle handle) const {
        FutureObject *obj = (FutureObject *)handle;
        return obj->futureStatus;
    }
    
    /// Return the API-specific error.
    /// Valid when GetFutureStatus() is kFutureStatusComplete, and undefined
    /// otherwise.
    int FutureDetail::GetFutureError(FutureHandle handle) const {
        FutureObject *obj = (FutureObject *)handle;
        return obj->futureError;
    }
    
    /// Return the API-specific error, in human-readable form, or "" if no message
    /// has been provided.
    /// Valid when GetFutureStatus() is kFutureStatusComplete, and undefined
    /// otherwise.
    const char* FutureDetail::GetFutureErrorMessage(FutureHandle handle) const {
        //FutureObject *obj = (FutureObject *)handle;
        return "";          // TODO
    }
    
    /// Return a pointer to the completed asynchronous result, or NULL if
    /// result is still pending.
    /// After an asynchronous call is marked complete, the API should not
    /// modify the result (especially on a callback thread), since the threads
    /// owning the Future can reference the result memory via this function.
    const void* FutureDetail::GetFutureResult(FutureHandle handle) const {
        FutureObject *obj = (FutureObject *)handle;
        return obj->futureResult;
    }
    
    /// Register a callback that will be called when this future's status is set
    /// to Complete. The result data will be passed back when the callback is
    /// called, along with the user_data supplied here.
    void FutureDetail::SetCompletionCallback(FutureHandle handle,
                                             FutureBase::CompletionCallback callback,
                                             void* user_data) {
        FutureObject *obj = (FutureObject *)handle;
        obj->callback = callback;
        obj->user_data = user_data;
    }
    
} //firebase