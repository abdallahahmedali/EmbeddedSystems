/*
 * BitMask.h
 *
 *  Created on: Sep 2, 2022
 *      Author: abdal
 */

#ifndef BITMASK_H_
#define BITMASK_H_


//BIT MASK
#define SET_BIT(REG,BIT)  REG |= (1 << BIT)
#define CLR_BIT(REG,BIT)  REG &=~(1 << BIT)
#define TOG_BIT(REG,BIT)  REG ^= (1 << BIT)
#define GET_BIT(REG,BIT)  ((REG >> BIT) & 1)

#endif /* BITMASK_H_ */
