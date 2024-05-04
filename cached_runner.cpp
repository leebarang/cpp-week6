#include "cached_runner.h"
#include <fstream>
#include <sstream>
#include <iostream>

// 생성자
CachedRunner::CachedRunner(Cache& cache) : cache(cache), hitCount(0), missCount(0), taskRunner(TaskRunner()) {}

// 캐시를 돌며 타겟 파일이 있다면 반환하고 hit을 올린다. 없으면 일반 방법 (taskRunner)를 사용해 파일을 캐시에 넣고,
// 반환하며 동시에 miss를 올린다.
double CachedRunner::multiply(std::string filename) {
    // 캐시에 결과가 있는지 확인
    double target;
    if (cache.get(filename, target)) {
        hitCount++;
        return target;
    } else {
        missCount++;
        // 결과가 없으면 일반 방법 사용
        double newFile = taskRunner.multiply(filename);
        // 캐시에 파일 새롭게 저장
        cache.add(filename, newFile);
        return newFile;
    }
}

// 캐시를 돌며 타겟 파일이 있다면 반환하고 hit을 올린다. 없으면 일반 방법 (taskRunner)를 사용해 파일을 캐시에 넣고,
// 반환하며 동시에 miss를 올린다.
int CachedRunner::palindrome(std::string filename) {
    // 캐시에 결과가 있는지 확인
    int target;
    if (cache.get(filename, target)) {
        hitCount++;
        return target;
    } else {
        missCount++;
        // 결과가 없으면 일반 방법 사용
        int newFile = taskRunner.palindrome(filename);
        // 캐시에 파일 새롭게 저장
        cache.add(filename, newFile);
        return newFile;
    }
}

// hit 반환
int CachedRunner::hits() {
    return hitCount;
}

// miss 반환
int CachedRunner::misses() {
    return missCount;
}