template <typename T>
List<T>::const_iterator::const_iterator()
{
    current = nullptr;
}

template <typename T>
const T& List<T>::const_iterator::operator*() const
{
    return this->retrieve();
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator++()
{
    this->current = this->current->next;
    return this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
{
    const_iterator old = *this;
    ++(*this);
    return old;
}

template <typename T>
typename List<T>::const_iterator& List<T>::const_iterator::operator--()
{
    this->current = this->current->prev;
    return this;
}

template <typename T>
typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
{
    const_iterator old = *this;
    --(*this);
    return old;
}

template <typename T>
bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
{
    return current == rhs.current;
}

template <typename T>
bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
{
    return current != rhs.current;
}

template <typename T>
List<T>::const_iterator::const_iterator(Node *p)
{
    current = p;
}

template <typename T>
T& List<T>::const_iterator::retrieve() const
{
    return this->current->data;
}

template <typename T>
List<T>::iterator::iterator()
{ }


template <typename T>
void List<T>::init()
{
    theSize=0;
    head = new List::Node;
    tail = new List::Node;
    head->next = tail;
    tail->prev = head;
    head->prev = nullptr;
    tail->next = nullptr;
}

template <typename T>
List<T>::List()
{
    init();
}

template <typename T>
int List<T>::size() const
{
    return theSize;
}

template <typename T>
bool List<T>::empty() const
{
    if(theSize > 0)
    {
        return true;
    }
    return false;
}

template <typename T>
T& List<T>::front()
{
    return *begin();
}

template <typename T>
const T& List<T>::front() const
{
    return *begin();
}

template <typename T>
T& List<T>::back()
{
    return *--end();
}

///TODO push and pop function
template <typename T>
void List<T>::push_front(const T& val)
{
    insert(begin(), val);
}

template <typename T>
void List<T>::push_front(T&& val)
{
    insert(begin(), std::move(val));
}

template <typename T>
void List<T>::push_back(const T& val)
{
    insert(end(), val);
}

template <typename T>
void List<T>::push_back(T&& val)
{
    insert(end(), std::move(val));
}

template <typename T>
void List<T>::pop_front()
{
    erase( begin());
}

template <typename T>
void List<T>::pop_back()
{
    erase( --end());
}



template <typename T>
const T& List<T>::back() const
{
    return *--end();
}

template <typename T>
typename List<T>::iterator List<T>::begin()
{
    return ( head->next );
}

template <typename T>
typename List<T>::const_iterator List<T>::begin() const
{
    return ( head->next );
}

template <typename T>
typename List<T>::iterator List<T>::end()
{
    return ( tail->prev );
}

template <typename T>
typename List<T>::const_iterator List<T>::end() const
{
    return ( tail->prev );
}

template <typename T>
typename List<T>::iterator List<T>::insert( iterator itr, const T& val)
{
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node{ val, p->prev, p }};
}

template <typename T>
typename List<T>::iterator List<T>::insert( iterator itr, T&& val)
{
    Node *p = itr.current;
    theSize++;
    return { p->prev = p->prev->next = new Node { std::move(val), p->prev, p }};
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator itr)
{
    Node *p = itr.current;
    iterator retVal{p->next};
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;

    return retVal;
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator start, iterator end)
{
    for ( iterator itr = start; itr != end; )
    {
        itr = erase( itr );
    }

    return end;
}


template <typename T>
List<T>::~List()
{
    delete head;
    delete tail;
}




/*template <typename T>
typename List<T>::iterator List<T>:erase(iterator itr)
{
    List<T>::Node *p = itr.current;
    List<T>::iterator retval(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    --theSize;
    return retval
}*/
