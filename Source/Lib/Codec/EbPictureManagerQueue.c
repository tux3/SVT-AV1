/*
* Copyright(c) 2019 Intel Corporation
* SPDX - License - Identifier: BSD - 2 - Clause - Patent
*/

#include <stdlib.h>
#include "EbPictureManagerQueue.h"

EbErrorType InputQueueEntryCtor(
    InputQueueEntry_t      **entryDblPtr)
{
    InputQueueEntry_t *entryPtr;
    EB_MALLOC(InputQueueEntry_t*, entryPtr, sizeof(InputQueueEntry_t), EB_N_PTR);
    *entryDblPtr = entryPtr;

    entryPtr->inputObjectPtr = (EbObjectWrapper_t*)EB_NULL;
    entryPtr->referenceEntryIndex = 0;
    entryPtr->dependentCount = 0;

    entryPtr->list0Ptr = (ReferenceList_t*)EB_NULL;
    entryPtr->list1Ptr = (ReferenceList_t*)EB_NULL;

    return EB_ErrorNone;
}



EbErrorType ReferenceQueueEntryCtor(
    ReferenceQueueEntry_t  **entryDblPtr)
{
    ReferenceQueueEntry_t *entryPtr;
    EB_MALLOC(ReferenceQueueEntry_t*, entryPtr, sizeof(ReferenceQueueEntry_t), EB_N_PTR);
    *entryDblPtr = entryPtr;

    entryPtr->referenceObjectPtr = (EbObjectWrapper_t*)EB_NULL;
    entryPtr->picture_number = ~0u;
    entryPtr->dependentCount = 0;
    entryPtr->referenceAvailable = EB_FALSE;

    EB_MALLOC(int32_t*, entryPtr->list0.list, sizeof(int32_t) * (1 << MAX_TEMPORAL_LAYERS), EB_N_PTR);

    EB_MALLOC(int32_t*, entryPtr->list1.list, sizeof(int32_t) * (1 << MAX_TEMPORAL_LAYERS), EB_N_PTR);

    return EB_ErrorNone;
}
