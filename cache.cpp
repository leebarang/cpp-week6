#include "cache.h"
#include <iostream>
#include <sstream>

// 생성자 구현
Cache::Cache() {
    head = nullptr;
    size = 0;
}

// 소멸자 구현
Cache::~Cache() {
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* target = current;
        current = current->next;
        delete target; // 각 값을 삭제
    }
}

// int value 를 캐시에 추가
void Cache::add(std::string key, int value) {
    if (size >= CACHE_SIZE) {
        // 만약 꽉 찼을 경우 가장 마지막의 값을 삭제
        LinkedList* target = head;
        LinkedList* previous = nullptr; // 이전 노드를 가리키는 포인터 추가

        // 끝까지 이동
        while (target->next != nullptr) {
            previous = target; // 현재 노드를 이전 노드로 설정
            target = target->next;
        }

        delete target; // 마지막 값 삭제

        if (previous == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            previous->next = nullptr;
        }
        size--;
    }

    LinkedList* node = new LinkedList;
    node->key = key;
    node->intValue = value;
    node->type = LinkedList::INT;
    node->next = head;
    head = node;
    size++;
}

// double value 를 캐시에 추가
void Cache::add(std::string key, double value) {
    if (size >= CACHE_SIZE) {
        // 만약 꽉 찼을 경우 가장 마지막의 값을 삭제
        LinkedList* target = head;
        LinkedList* previous = nullptr; // 이전 노드를 가리키는 포인터 추가

        // 끝까지 이동
        while (target->next != nullptr) {
            previous = target; // 현재 노드를 이전 노드로 설정
            target = target->next;
        }

        delete target; // 마지막 값 삭제

        if (previous == nullptr) {
            delete head;
            head = nullptr;
        }
        else {
            previous->next = nullptr;
        }
        size--;
    }

    LinkedList* node = new LinkedList;
    node->key = key;
    node->doubleValue = value;
    node->type = LinkedList::DOUBLE;
    node->next = head;
    head = node;
    size++;
}

// int value 를 캐시에서 찾기 + 있다면 맨 앞으로 이동
bool Cache::get(std::string key, int &value) {
    LinkedList* target = head;
    LinkedList* previous = nullptr; // 이전 노드를 가리키는 포인터 추가
    while (target != nullptr) {
        // INT
        if (target->key == key && (target->type == LinkedList::INT)) {
            value = target->intValue;
            // 찾은 노드가 이미 맨 앞에 있는 경우
            if (previous == nullptr) {
                return true;
            }

            // 찾은 노드를 맨 앞으로 이동
            previous->next = target->next; // 이전 노드의 next를 찾은 노드의 next로 설정
            target->next = head; // 찾은 노드의 next를 현재 head로 설정
            head = target; // head를 찾은 노드로 변경

            return true;
        }
        previous = target;
        target = target->next;
    }
    return false;
}

// double value 를 캐시에서 찾기 + 있다면 맨 앞으로 이동
bool Cache::get(std::string key, double &value) {
    LinkedList* target = head;
    LinkedList* previous = nullptr; // 이전 노드를 가리키는 포인터 추가
    while (target != nullptr) {
        // DOUBLE
        if (target->key == key && (target->type == LinkedList::DOUBLE)) {
            value = target->doubleValue;
            // 찾은 노드가 이미 맨 앞에 있는 경우
            if (previous == nullptr) {
                return true;
            }

            // 찾은 노드를 맨 앞으로 이동
            previous->next = target->next; // 이전 노드의 next를 찾은 노드의 next로 설정
            target->next = head; // 찾은 노드의 next를 현재 head로 설정
            head = target; // head를 찾은 노드로 변경

            return true;
        }
        previous = target;
        target = target->next;
    }
    return false;
}

// toString()
std::string Cache::toString() {
    std::ostringstream oss;
    LinkedList* target = head; // 가장 첫번째(head) 에서 시작
    bool isFirst = true;

    while (target != nullptr) {
        if (!isFirst) {
            // 첫 번째 캐시가 아닌 경우에만 "->" 출력
            oss << " -> ";
        } else {
            isFirst = false; // 첫 번째 캐시를 처리한 후에는 false로 변경
        }

        oss << "[";

        // 키가 palindrome인지 multiply인지 확인
        if (target->key.find("palindrome") != std::string::npos) {
            oss << "palindrome(";
        } else if (target->key.find("multiply") != std::string::npos) {
            oss << "multiply(";
        }

        // 키 출력
        oss << target->key << "): ";

        // INT value 출력
        if (target->type == LinkedList::INT) {
            oss << target->intValue;
        }
        // DOUBLE value 출력
        else if (target->type == LinkedList::DOUBLE){
            oss << target->doubleValue;
        }

        oss << "]";

        // 다음으로 이동
        target = target->next;
    }
    oss << "\n";
    return oss.str();
}