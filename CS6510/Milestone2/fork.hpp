//
//  fork.hpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/30/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#ifndef fork_hpp
#define fork_hpp

#include <stdio.h>
#include "scheduler.hpp"
#include "pcb.hpp"


class Fork {
public:
	Fork(Pcb* p);
};


#endif /* fork_hpp */
