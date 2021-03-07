/**
 *    @file
 *    
 *    @author Trevor Hickey
 *    
 *    @note Lock Actions Interface
 *    
 *    @brief decision actions taken on priority locks
 *    
 *    @details Contains whether or not locks should be utilized and deciding when to unlock
 *    
 *    @copyright Copyright 2015.
 *    @n         Fidelity Flight Simulation, Inc. (F2Si)
 *    @n         All rights reserved.
 *    
 *    @b Classification:      Unclassified
 *    
 *    @b Project @b Name:     UH-72A Synthetic Flight Training System (SFTS)
 *    
 *    @b Contract @b Number:  #W900KK-09-D-0577
 *    
 *    @b Task @b Order:       0002
 *    
 *    This work was generated under U.S. Government contract and the
 *    government has unlimited data rights therein.
 *    
 *    @b DISTRIBUTION @b STATEMENT @b D:
 *    @n    Distribution authorized to the Department of Defense and U.S. DoD contractors only.
 *    @n    Other requests shall be referred to the controlling DoD office.
 *    
 *    @b Organizations:
 *    @n    Fidelity Flight Simulation, Inc. (F2Si)
 *    @n    1815 Parkway View Drive
 *    @n    Pittsburgh, PA 15205
 *    @n    (412) 321-3280
 *    
 *    @addtogroup Electrical
 *    @{
 *    
 */
#ifndef LockActionsH
#define LockActionsH




#ifdef __cplusplus
extern "C"
{
#endif /* #ifdef __cplusplus */


/**
 * @brief   how to open a lock based on priorities
 * @details a malfunction may decide to unlock the node based on a matching or sufficient priority
 */
typedef enum UnlockAction_e
{
UNLOCK_ACTION_MATCH_PRIORITY,/* the priority lock should only be released if priorities match */
UNLOCK_ACTION_SUFFICIENT_PRIORITY/* the priority lock should only be released if the priority is sufficient (<= current priority) */

} UnlockActionE;



/**
 * @brief   whether or not a lock should be used when affecting a node's state
 * @details using a lock can apply to anything that changes the state of a graph node
 */
typedef enum UseLock_e
{
USE_LOCK_YES,/* the lock should be utilized when taking an action on a node */
USE_LOCK_NO/* the lock should not be utilized when taking an action on a node */

} UseLockE;




/**
 * @brief     converts unlock action to a string
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string
 * @return    a string representing the enumerated value
 */
const char* UnlockActionToStr(const UnlockActionE eUnlockAction);

/**
 * @brief     converts use lock to a string
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string
 * @return    a string representing the enumerated value
 */
const char* UseLockToStr(const UseLockE eUseLock);

/**
 * @brief     converts unlock action to a string
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string
 * @param[In] nAmount       the number of unlock actions
 * @return    a string representing the enumerated value
 */
const char* UnlockActionToInflectedStr(const UnlockActionE eUnlockAction, const int nAmount);

/**
 * @brief     converts use lock to a string
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string
 * @param[In] nAmount  the number of use locks
 * @return    a string representing the enumerated value
 */
const char* UseLockToInflectedStr(const UseLockE eUseLock, const int nAmount);


#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

#endif /* LockActionsH */

///@}

