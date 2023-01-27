#include <cstddef>
#include <iostream>

#include <stdexcept>
#include "ulliststr.h"

using namespace std;


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


/**
  * Adds a new value to the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::push_back(const string& val){
  if(size_ == 0){
    Item* newItem = new Item;
    head_ = newItem;
    tail_ = newItem;
    newItem->val[0] = val;
    newItem->last = 1;

  }
  else if(tail_->last == ARRSIZE){
    Item* newItem = new Item;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    newItem->val[0] = val;
    newItem->last = 1;

  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last += 1;

  }
  size_++;
  // cout << "Success" << endl;
}

/**
  * Removes a value from the back of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_back(){
  if(size_ == 0){
    return;
  }
  if(tail_->first == tail_->last-1){
    bool check = false;
    if(head_ == tail_)
      check = true;
    else
    {
      Item* oldBack = tail_;
      tail_ = tail_->prev;
      if(tail_){
        tail_->next = nullptr;
      }
      delete oldBack;
      oldBack = nullptr;
    }

    if(check)
    {
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
    }
    //]oldFront = nullptr;
}
  else{
    tail_->last -= 1;
  }
  size_--;
}


/**
  * Removes a value from the front of the list
  *   - MUST RUN in O(1)
  */
void ULListStr::pop_front(){
  // cout << "A" << endl;
    if(size_ == 0){
      return;
    }
    // cout << "B" << endl;

    if(head_->first == head_->last-1){
      bool check = false;
      if(head_ == tail_)
        check = true;
      else
      {
        Item* oldFront = head_;
        head_ = head_->next;
        if(head_){
          head_->prev = nullptr;
        }
        delete oldFront;
        oldFront = nullptr;
      }

      if(check)
      {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
      }
      //]oldFront = nullptr;
  }
  else{
    head_->first += 1;
  }
  // cout << "C" << endl;

  size_--;
}



/**
  * Adds a new value to the front of the list.
  * If there is room before the 'first' value in
  * the head node add it there, otherwise, 
  * allocate a new head node.
  *   - MUST RUN in O(1)
  */
void ULListStr::push_front(const string& val){
  if(size_ == 0){
    Item* newItem = new Item;
    head_ = newItem;
    tail_ = newItem;
    newItem->val[ARRSIZE-1] = val;
    newItem->last = ARRSIZE;
    newItem->first = ARRSIZE-1;
  }
  else if(head_->first == 0){
    Item* newItem = new Item;
    head_->prev = newItem;
    newItem->next = head_;
    head_ = newItem;
    newItem->val[ARRSIZE-1] = val;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;

  }
  else{
    head_->val[head_->first-1] = val;
    head_->first -= 1;
  }
  size_++;
}


/**
  * Returns a const reference to the back element
  *   - MUST RUN in O(1)
  */
string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

/**
  * Returns a const reference to the front element
  *   - MUST RUN in O(1)
  */
string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

// grade_ulliststr

  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_){
    return nullptr;
  }
  Item* temp;
  temp = head_;

  int countDown = loc;

  while(true){
    int sizeOfCurr = temp->last - temp->first;
    if(countDown < sizeOfCurr){
      return &temp->val[temp->first + countDown];
    }

    countDown -= (temp->last - temp->first);
    temp = temp->next;
  }
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

