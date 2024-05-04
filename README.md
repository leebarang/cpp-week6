# LRU Cache 프로그램
이 프로그램은 데이터를 읽어오는 과정에서 수행하는 Cache 를 구현한 프로그램입니다.   
사용자는 resources 파일을 통해 Cache가 정상 작동하는지 확인할 수 있습니다.  
스켈레톤 코드 및 template은 https://github.com/cstria0106/cache-template.git 에서 확인할 수 있습니다.   
@version 1.0.0

## 실행 방법
프로젝트를 다운로드하고 소스 코드를 가져옵니다.  
컴파일러가 C++11 이상을 지원하는지 확인합니다.  
미리 작성한 Makefile을 통해 실행합니다.
* 본 프로그램에서는 mingw32-make를 사용했습니다.  
```
git clone https://github.com/leebarang/cpp-week6.git cache
cd cache
git submodule update --init

make #mingw32-make
./main.exe
```

## 주의사항
이 프로그램의 최적의 효율성이 고려되지 않았으므로 프로그램 동작 속도가
항상 최적화 되어있지 않을 수 있습니다.