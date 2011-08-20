/*
 * vm
 * Copyright (C) Fernando Arroba Rubio 2011 <gnotxor@gmail.com>
 * 
 * vm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * vm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LIST_H
#define __LIST_H

#include "Stackable.h"
#include "class.h"

namespace objfenix {

	class List: public Class{
	private:
		~List();
		vector<Class*> list;
	public:
		List();
		long getSize() {return list.size();};
		
	};

}
#endif //__LIST_H
