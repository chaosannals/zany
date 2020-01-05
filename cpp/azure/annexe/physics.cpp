#include "physics.h"

void anx::interact(particle &l, particle &r){
	l.affect(r);
	r.affect(l);
}
