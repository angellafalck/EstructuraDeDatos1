#ifndef _SORT_H
#define _SORT_H

#include <list>

// Sort a list using selection sort
template<typename TElem>
void sortList(std::list<TElem>& lst)
{
  for(typename std::list<TElem>::iterator it =lst.begin(); it != lst.end(); i++)
  {
    lst.sort();
  }
  
}

#endif
