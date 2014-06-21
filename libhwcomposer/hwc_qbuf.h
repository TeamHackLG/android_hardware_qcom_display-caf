/*
 * Copyright (C) 2010 The Android Open Source Project
 * Copyright (C) 2012, Code Aurora Forum. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gralloc_priv.h>

// -----------------------------------------------------------------------------
// QueuedBufferStore
//This class holds currently and previously queued buffers.
//Provides utilities to store, lock, remove, unlock.

namespace qhwc{
static const int MAX_QUEUED_BUFS = 4;
class QueuedBufferStore {
    public:
    QueuedBufferStore() {
        clearCurrent();
        clearPrevious();
    }
    ~QueuedBufferStore() {}
    void lockAndAdd(private_handle_t*);
    //Unlocks only previous and makes the current as previous
    void unlockAllPrevious();
    //Unlocks previous as well as current, useful in suspend case
    void unlockAll();

    private:
    QueuedBufferStore& operator=(const QueuedBufferStore&);
    QueuedBufferStore(const QueuedBufferStore&);
    bool lockBuffer(private_handle_t *hnd);
    void unlockBuffer(private_handle_t *hnd);
    void clearCurrent();
    void clearPrevious();
    void mvCurrToPrev();

    //members
    private_handle_t *current[MAX_QUEUED_BUFS]; //holds buf being queued
    private_handle_t *previous[MAX_QUEUED_BUFS]; //holds bufs queued in prev round
    int curCount;
    int prevCount;
};

//Store and lock current drawing round buffers
inline void QueuedBufferStore::lockAndAdd(private_handle_t *hnd) {
}

//Unlock all previous drawing round buffers
inline void QueuedBufferStore::unlockAllPrevious() {
}

inline void QueuedBufferStore::unlockAll() {
}

//Clear currentbuf store
inline void QueuedBufferStore::clearCurrent() {
}

//Clear previousbuf store
inline void QueuedBufferStore::clearPrevious() {
}

//Copy from current to previous
inline void QueuedBufferStore::mvCurrToPrev() {
}

inline bool QueuedBufferStore::lockBuffer(private_handle_t *hnd) {
    return true;
}

inline void QueuedBufferStore::unlockBuffer(private_handle_t *hnd) {
}
// -----------------------------------------------------------------------------
};//namespace

