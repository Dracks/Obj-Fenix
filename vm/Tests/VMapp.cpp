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

#include <cppunit/ui/text/TestRunner.h>
#include "ObjectTest.h"

int main(int argc, char* argv[])
{
  CPPUNIT_NS::TextUi::TestRunner runner;

  runner.addTest( suite );

  bool wasSucessful = runner.run();

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}
