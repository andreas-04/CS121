/**
 * @file linked_list.hpp
 * @author Austin Walker (ajwblueidaho@outlook.com)
 * @brief defines a class used for a link list of integers
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#define linkError "Runtime Error: Linked List: "

/**
 * @brief defines a node of the linked list
 * @note there is no point to have a node with empty values
 * 
 */
struct list_node
{
    list_node* last; //points to the value that came before this node
    list_node* next; //points to the value that came after this node
    int value; //value of the node

    /**
     * @brief Construct a new list node object
     * @note Used for the head of a list during initialization, therefore it points to no other node, and no other node points to it (it will be the only node) 
     * 
     * @param val value of the new node
     */
    list_node(int val)
    {
        next = NULL;
        last = NULL;
        value = val;
    }
    
    /**
     * @brief Construct a new list node object
     * @note Used when adding a node to the end of a list
     * 
     * @param l pointer that points to a node that came before this new node
     * @param val value of the new node
     */
    list_node(list_node* l, int val)
    {
        last = l;
        value = val;
        next = NULL;
    }
    
    /**
     * @brief Construct a new list node object
     * @note Used when adding a node to the middle of a list
     * 
     * @param l pointer that points to the node indexed before the new node
     * @param n pointer that points to the node indexed after the new node
     * @param val value of the new node
     */
    list_node(list_node* l, list_node* n, int val)
    {
        last = l;
        next = n;
        value = val;
    }
};

class linked_list
{
    list_node* head; //start of list
    list_node* current; //the node the list either stopped after a function at or is currently using for a function
    list_node* tail; //end of list
    int sizeV; //total size of the list, oh an V is for variable. I used size() for a function, inspired by java

    /**
     * @brief Advances the current pointer to the specified index
     * 
     * @param index the index to advance current to
     * @return true the function found the index specified
     * @return false the function terminated early, meaning the index was out of bounds and current is at the end of the list
     */
    bool advanceTo(int index)
    {
        current = head;
        try
        {
            for(int i = 0; i < index; i ++)
            {
                if(current->next == NULL)
                {
                    throw std::runtime_error("Index is out of bounds");
                    break;
                }
                current = current->next;
            }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << linkError << "advanceTo call: " << e.what() << '\n';
            return false;
        }
        return true;
    }

    /**
     * @brief initialize the list with its first value
     * 
     * @param val the first value the list will have
     */
    void init(int val)
    {
        head = new list_node(val);
        tail = head;
        current = head;
        sizeV = 1;
    }

    public:

    /**
     * @brief advances to the next node, and returns its value
     * 
     * @return int value of the next node
     */
    int next()
    {
        //error checking
        try
        {
            if(sizeV == 0)
            {
                throw std::runtime_error("List needs to be initialized");
            }
            if(current->next == NULL)
            {
                throw std::runtime_error("Next goes Out of Bounds");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << linkError << "next call: " << e.what() << '\n';
            return 0;
        }

        current = current->next;
        return current->value;
    }

    /**
     * @brief goes back one node, and returns its value
     * 
     * @return int value of the node
     */
    int last()
    {
        //error checking
        try
        {
            if(sizeV == 0)
            {
                throw std::runtime_error("List needs to be initialized");
            }
            if(current->last == NULL)
            {
                throw std::runtime_error("last goes Out of Bounds");
            }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << linkError << "last call: " << e.what() << '\n';
            return 0;
        }
        
        current = current->last;
        return current->value;
    }

    /**
     * @brief finds the value stored in the node at a specified index
     * 
     * @param index index of node
     * @return int value of node
     */
    int find(int index)
    {
        //error checking
        try
        {
            if(sizeV == 0)
            {
                throw std::runtime_error("List needs to be initialized");
            }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << linkError << "find call:   " << e.what() << '\n';
            return 0;
        }
        if(advanceTo(index))
        {
            return current->value;
        }
        return 0;
    }

    /**
     * @brief chnages the value of a node
     * 
     * @param index index of node
     * @param val new value of node
     */
    void change(int index, int val)
    {
        //error checking
        try
        {
            if(sizeV == 0)
            {
                throw std::runtime_error("List needs to be initialized");
            }
            if(!advanceTo(index))
            {
                throw std::runtime_error("Index out of bounds");
            }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << linkError << "change call: " << e.what() << '\n';
            return;
        }
        
        current->value = val;
    }

    /**
     * @brief adds a node to the end of the list
     * 
     * @param val valude of the new node
     */
    void add(int val)
    {
        if(sizeV == 0) //for error checking
        {
            init(val);
        } else
        {
            list_node* temp;
            temp = tail;
            tail = new list_node(temp, val);
            temp->next = tail;
            sizeV ++;
        }
    }

    /**
     * @brief adds a node at a specified index
     * 
     * @param val value of the new node
     * @param index index to place new node
     */
    void add(int val, int index)
    {
        if(sizeV == 0)
        {
            init(val);
            return;
        }
        list_node* temp;
        if(!advanceTo(index))
        {
            std::cerr << "add(int, int) call: Index out of bounds, value " << val << " added to the end of the list.";
            add(val);
            return;
        }
        //bind temp by setting its last to current's last, and its next to current
        temp = new list_node(current->last, current, val);
        //rebind current's last by setting its next to temp, only if current is not the head
        if(index != 0)
        {
            current->last->next = temp;
        } else
        {
            head = temp;
        }
        //rebind current by setting its last to temp
        current->last = temp;
        sizeV ++;
    }

    /**
     * @brief deletes the last node of the list
     * 
     * @return int value ofthe deleted node
     */
    int del()
    {
        //error checking
        try
        {
            if(sizeV == 0)
            {
                throw std::runtime_error("There are no items to delete please initialize the list first");
            }
        }
        catch(const std::runtime_error& e)
        {
            std::cerr << linkError << "del() call: " << e.what() << '\n';
            return 0;
        }

        list_node* temp;
        int val = tail->value;
        temp = tail->last;
        delete tail;
        tail = temp;
        tail->next = NULL;
        sizeV --;
        return val;
    }

    /**
     * @brief deletes the node at a specified index
     * 
     * @param index index of node to delete
     * @return int value of deleted node
     */
    int del(int index)
    {
        //error checking
        bool indexOut = 0;
        try
        {
            if(sizeV == 0)
            {
                throw std::runtime_error("There are no items to delete, please initialize the list first");
                return 0;
            }
            if(!advanceTo(index))
            {
                throw std::runtime_error("Last value in the list was deleted");
                indexOut = 1;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << linkError << "indexOut call: " << e.what() << '\n';
        }
        if(indexOut)
        {
            return del();
        }
        
        list_node* temp;
        int val = current->value;
        if(index == 0)
        {
            temp = current->next;
            head = temp;
            temp->last = NULL;
        } else if(index + 1 == sizeV)
        {
            return del();
        } else
        {
            temp = current->last;
            temp->next = current->next;
            temp = current->next;
            temp->last = current->last;
        }
        delete current;
        current = temp;
        sizeV --;
        return val;
    }

    /**
     * @brief get the size of the list
     * 
     * @return size of the list
     */
    int size()
    {
        return sizeV;
    }

    //constructors
    /**
     * @brief Construct a new linked list object
     * @note used when there is a value for the first node ready
     * 
     * @param val value of the first node
     */
    linked_list(int val)
    {
        init(val);
        sizeV = 1;
    }

    /**
     * @brief Construct a new linked list object
     * @note used when there are no values ready for the new list
     * 
     */
    linked_list()
    {
        head = NULL;
        current = NULL;
        tail = NULL;
        sizeV = 0;
    }

    //deconstructors, demolishers, destroyers (nope definetly not that one), ummmmmmm..... I forgot the name
    /**
     * @brief Destroy the linked list object
     * 
     */
    ~linked_list()
    {
        while(sizeV > 1)
        {
            del();
        }
        delete tail;
    }
};