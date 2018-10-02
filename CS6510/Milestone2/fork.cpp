//
//  fork.cpp
//  Sandbox-classes
//
//  Created by TJ Nielsen on 9/30/18.
//  Copyright © 2018 TJ Nielsen. All rights reserved.
//

#include "fork.hpp"

Fork::Fork(Pcb* p) {
	p->setForking(true);
	p->setForkedParent(true);
	//p->addForkedChildren(sched->spawnChild(p));
}
