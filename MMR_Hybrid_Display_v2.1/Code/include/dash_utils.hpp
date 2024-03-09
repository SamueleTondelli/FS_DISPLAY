#pragma once

#define TSAFE_QUEUE_MAXLENGTH 20
#define HMAP_MAXSIZE 50

#include <string.h>
#include <iostream>
#include "ps_code.hpp"

template <typename T> class TSafeQueue
{
public:
	TSafeQueue() :m_queue(), m_queueSize(0) {}

	bool push(T* e)
	{
		m_locker.acquireLock();
		bool ret = basicPush(e);
		m_locker.giveLock();
		return ret;
	}

	T* peek()
	{
		m_locker.acquireLock();
		T* ret = basicPeek();
		m_locker.giveLock();
		return ret;
	}

	T* pop()
	{
		m_locker.acquireLock();
		T* ret = basicPop();
		m_locker.giveLock();
		return ret;
	}

	bool isQueueFull()
	{
		return m_queueSize >= TSAFE_QUEUE_MAXLENGTH;
	}

private:
	T* m_queue[TSAFE_QUEUE_MAXLENGTH];
	size_t m_queueSize;
	Locker m_locker;

	bool basicPush(T* e)
	{
		if (isQueueFull()) return false;
		m_queue[m_queueSize] = e;
		m_queueSize++;
		return true;
	}

	T* basicPeek()
	{
		return m_queue[0];
	}

	T* basicPop()
	{
		if (m_queueSize == 0) return NULL;
		m_queueSize--;
		T* ret = m_queue[0];
		memcpy((void*)m_queue, (void*)(m_queue + 1), m_queueSize * sizeof(T*));
		m_queue[m_queueSize] = NULL;
		return ret;
	}
};

/* Entry for map */
template<typename K, typename V> class Entry
{
public:
	Entry() :Entry(NULL, NULL) {}
	Entry(K key, V value) :m_key(key), m_value(value) {}

	K getKey()
	{
		return m_key;
	}

	V getValue()
	{
		return m_value;
	}

	void setKey(K key)
	{
		m_key = key;
	}

	void setValue(V value)
	{
		m_value = value;
	}

private:
	K m_key;
	V m_value;
};

//consider maybe making this thread safe
template<typename K, typename V> class HashMap
{
public:
	typedef int (*compareFn_t) (K, K);
	typedef unsigned long (*hashFn_t) (K);

	HashMap(hashFn_t hash, compareFn_t comp) :m_map(), m_mapSize(0), m_hash(hash), m_comp(comp) {}

	bool add(K key, V value)
	{
		if (isMapFull()) return false;
		size_t startPos = m_hash(key) % HMAP_MAXSIZE;
		while (m_map[startPos].getKey() != NULL) { startPos = (startPos + 1) % HMAP_MAXSIZE; }
		m_map[startPos].setKey(key);
		m_map[startPos].setValue(value);
		return true;
	}

	Entry<K, V>* get(K key)
	{
		size_t startPos = m_hash(key) % HMAP_MAXSIZE;
		size_t i = startPos;
		K t;
		while ((t = m_map[i].getKey()) != NULL)
		{
			if (m_comp(t, key) == 0) return m_map + i;
			i = (i + 1) % HMAP_MAXSIZE;
			if (i == startPos) {
				break;
			}
		}
		return NULL;
	}

	bool isMapFull()
	{
		return m_mapSize >= HMAP_MAXSIZE;
	}

private:
	Entry<K, V> m_map[HMAP_MAXSIZE];
	size_t m_mapSize;
	hashFn_t m_hash;
	compareFn_t m_comp;
};

// https://stackoverflow.com/a/7666577
unsigned long hashCstr(char* key);

int compCstr(char* s1, char* s2);

void safeStringCopy(const char* src, char* dst, size_t dstSize);
