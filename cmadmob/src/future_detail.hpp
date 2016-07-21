//
//  future_detail.hpp
//  AdExample
//
//  Created by jinlongfei on 16/7/21.
//  Copyright © 2016年 Long Way Studio. All rights reserved.
//

#ifndef future_detail_hpp
#define future_detail_hpp

#include <future>
#include "firebase/future.h"

namespace firebase {
    
    //负责引用计数的容器，handle是真正的对象
    class FutureDetail: public firebase::detail::FutureApiInterface {
    public:
        
        FutureDetail() : mCount(0) {}
        
        /// Increment the reference count on handle's asynchronous call.
        /// Called when the Future is copied.
        virtual void ReferenceFuture(FutureHandle handle);
        
        /// Decrement the reference count on handle's asynchronous call.
        /// Called when the Future is destroyed or moved.
        /// If the reference count drops to zero, the asynchronous call can be
        /// forgotten.
        virtual void ReleaseFuture(FutureHandle handle);
        
        /// Return the status of the asynchronous call.
        virtual FutureStatus GetFutureStatus(FutureHandle handle) const;
        
        /// Return the API-specific error.
        /// Valid when GetFutureStatus() is kFutureStatusComplete, and undefined
        /// otherwise.
        virtual int GetFutureError(FutureHandle handle) const;
        
        /// Return the API-specific error, in human-readable form, or "" if no message
        /// has been provided.
        /// Valid when GetFutureStatus() is kFutureStatusComplete, and undefined
        /// otherwise.
        virtual const char* GetFutureErrorMessage(FutureHandle handle) const;
        
        /// Return a pointer to the completed asynchronous result, or NULL if
        /// result is still pending.
        /// After an asynchronous call is marked complete, the API should not
        /// modify the result (especially on a callback thread), since the threads
        /// owning the Future can reference the result memory via this function.
        virtual const void* GetFutureResult(FutureHandle handle) const;
        
        /// Register a callback that will be called when this future's status is set
        /// to Complete. The result data will be passed back when the callback is
        /// called, along with the user_data supplied here.
        virtual void SetCompletionCallback(FutureHandle handle,
                                           FutureBase::CompletionCallback callback,
                                           void* user_data);
        
    private:
        int mCount;
    };
    
    class  FutureObject {
    public:
        FutureObject() {}
        std::future<void> future;
        
        FutureStatus futureStatus;
        int futureError;
        void *futureResult;
        
        FutureBase::CompletionCallback callback;
        void *user_data;
    };
    
} // firebase


#endif /* future_detail_hpp */
