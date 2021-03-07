/**
 *    @file
 *    
 *    @author Trevor Hickey
 *    
 *    @note Lock Actions Implementation
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
#include "LockActions.h"  // implements declarations


/**
 * @brief     converts unlock action to a string in its singular form
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string in singular form
 * @return    a string representing the enumerated value
 */
static const char* UnlockActionToSingularStr(const UnlockActionE eUnlockAction);

/**
 * @brief     converts use lock to a string in its singular form
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string in singular form
 * @return    a string representing the enumerated value
 */
static const char* UseLockToSingularStr(const UseLockE eUseLock);

/**
 * @brief     converts unlock action to a string in its plural form
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string in plural form
 * @return    a string representing the enumerated value
 */
static const char* UnlockActionToPluralStr(const UnlockActionE eUnlockAction);

/**
 * @brief     converts use lock to a string in its plural form
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string in plural form
 * @return    a string representing the enumerated value
 */
static const char* UseLockToPluralStr(const UseLockE eUseLock);

/**
 * @brief     converts unlock action to a string
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string
 * @return    a string representing the enumerated value
 */
const char* UnlockActionToStr(const UnlockActionE eUnlockAction)
{
//convert enum to a string
return UnlockActionToSingularStr(eUnlockAction);
}

/**
 * @brief     converts use lock to a string
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string
 * @return    a string representing the enumerated value
 */
const char* UseLockToStr(const UseLockE eUseLock)
{
//convert enum to a string
return UseLockToSingularStr(eUseLock);
}

/**
 * @brief     converts unlock action to a string
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string
 * @param[In] nAmount       the number of unlock actions
 * @return    a string representing the enumerated value
 */
const char* UnlockActionToInflectedStr(const UnlockActionE eUnlockAction, const int nAmount)
{
//decide whether to convert the enumerated string in singular or plural form
if(nAmount == 1){
return 
UnlockActionToSingularStr(eUnlockAction);
}
return UnlockActionToPluralStr(eUnlockAction);
}

/**
 * @brief     converts use lock to a string
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string
 * @param[In] nAmount  the number of use locks
 * @return    a string representing the enumerated value
 */
const char* UseLockToInflectedStr(const UseLockE eUseLock, const int nAmount)
{
//decide whether to convert the enumerated string in singular or plural form
if(nAmount == 1){
return 
UseLockToSingularStr(eUseLock);
}
return UseLockToPluralStr(eUseLock);
}

/**
 * @brief     converts unlock action to a string in its singular form
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string in singular form
 * @return    a string representing the enumerated value
 */
static const char* UnlockActionToSingularStr(const UnlockActionE eUnlockAction)
{
//convert enum to a string
switch(eUnlockAction){
case UNLOCK_ACTION_MATCH_PRIORITY: return "match priority"; break;
case UNLOCK_ACTION_SUFFICIENT_PRIORITY: return "sufficient priority"; break;
}
return "unknown";

}

/**
 * @brief     converts use lock to a string in its singular form
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string in singular form
 * @return    a string representing the enumerated value
 */
static const char* UseLockToSingularStr(const UseLockE eUseLock)
{
//convert enum to a string
switch(eUseLock){
case USE_LOCK_YES: return "yes"; break;
case USE_LOCK_NO: return "no"; break;
}
return "unknown";

}

/**
 * @brief     converts unlock action to a string in its plural form
 * @details   converts enum to string
 * @param[In] eUnlockAction the unlock action to convert to a string in plural form
 * @return    a string representing the enumerated value
 */
static const char* UnlockActionToPluralStr(const UnlockActionE eUnlockAction)
{
//convert enum to a string
switch(eUnlockAction){
case UNLOCK_ACTION_MATCH_PRIORITY: return "match priorities"; break;
case UNLOCK_ACTION_SUFFICIENT_PRIORITY: return "sufficient priorities"; break;
}
return "unknowns";

}

/**
 * @brief     converts use lock to a string in its plural form
 * @details   converts enum to string
 * @param[In] eUseLock the use lock to convert to a string in plural form
 * @return    a string representing the enumerated value
 */
static const char* UseLockToPluralStr(const UseLockE eUseLock)
{
//convert enum to a string
switch(eUseLock){
case USE_LOCK_YES: return "yeses"; break;
case USE_LOCK_NO: return "noes"; break;
}
return "unknowns";

}

///@}

