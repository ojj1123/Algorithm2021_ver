# 3강 : 배열

- 배열 : 메모리 상에 원소를 연속하게 배치한 자료구조
- 배열의 성질
  1.  O(1)에 k번째 원소를 확인/변경 가능
  2.  추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음(다른 자료구조랑 비교)
  3.  Cache hit rate가 높음
  4.  메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림
- 시간복잡도
  1.  임의의 위치에 있는 원소를 확인/변경 = O(1)
  2.  원소를 끝에 추가 = O(1)
  3.  마지막 원소를 제거 = O(1)
  4.  임의의 위치에 원소를 추가/임의 위치의 원소 제거 = O(N)
- STL iterator란?
- C++개념 다시 복습
  1. 참조자, deep copy, call by reference, call by value 등
  2. range-based for loop
  3. int& e:v1 VS int e:v1
