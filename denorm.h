/*
 *
 * This file implements "CREATE TABLE x AS redis_datastructure"
 *

GPL License

Copyright (c) 2010 Russell Sullivan <jaksprats AT gmail DOT com>
ALL RIGHTS RESERVED 

   This file is part of AlchemyDatabase

    AlchemyDatabase is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AlchemyDatabase is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with AlchemyDatabase.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DENORM__H
#define __DENORM__H

#include "common.h"
#include "redis.h"

#define NUM_ACCESS_TYPES              14
#define ACCESS_SELECT_COMMAND_NUM      0
//#define ACCESS_SCANSELECT_COMMAND_NUM  1
void createTableAsObject(redisClient *c);

bool emptyNoop(redisClient *c);
#define PIPE_NONE_FLAG      0
#define PIPE_ERR_FLAG       1
#define PIPE_ONE_LINER_FLAG 2
#define PIPE_EMPTY_SET_FLAG 3
long fakeClientPipe(redisClient *c,
                    redisClient *rfc,
                    void        *wfc,
                    int          is_ins,
                    flag        *flg,
                    bool (* adder)
                    (redisClient *c, void *x, robj *key, long *l, int b, int n),
                    bool (* emptyer)(redisClient *c));
#endif /* __DENORM__H */
