#ifndef CACHE_H
#define CACHE_H

#include <string>

#define CACHE_SIZE 10
// #define HASH_SIZE 20

// 해시 클래스
// class Hash {
// public:
//   // 해시 함수
//   int hash(std::string key);
// };

// 연결 리스트
typedef struct LinkedList {
  std::string key;
  enum ValueType { INT, DOUBLE }; // value의 타입을 저장하는 enum
  ValueType type; // 저장된 타입 int or double
  int intValue; // 찾고자 하는 값 int
  double doubleValue; // 찾고자 하는 값 double
  LinkedList* next; // 다음 노드의 위치
  LinkedList() {};
  LinkedList(std::string key, int value) : key(key), type(INT), intValue(value), next(nullptr) {};
  LinkedList(std::string key, double value) : key(key), type(DOUBLE), doubleValue(value), next(nullptr) {};
} LinkedList;

class Cache {
private:
  int size; // 현재 캐시 사이즈
  LinkedList* head; // 헤드 포인트
  // LinkedList* table[HASH_SIZE]; // 해시의 링크드 리스트 테이블

public:
  Cache();
  ~Cache();
  // int를 cache에 추가한다
  void add(std::string key, int value);
  // double을 cache에 추가한다
  void add(std::string key, double value);
  // key에 해당하는 value를 cache에서 가져온다
  // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
  bool get(std::string key, int &value);
  // key에 해당하는 value를 cache에서 가져온다.
  // 타입과 key가 동일한 원소가 없다면 false를 반환한다.
  bool get(std::string key, double &value);

  // 디버그 및 채점 용: 연결 리스트를 문자열로 표현하여 반환한다
  // 다음과 같이 표현된 문자열을 반환한다
  // [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
  std::string toString();
};

#endif