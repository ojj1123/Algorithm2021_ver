# deque
- restricted structure
- 앞/뒤 모두 삽입/삭제 가능
- 덱은 메모리상에 연속적으로 존재하지 않음

- Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways: While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators).
--> 덱과 백터의 차이를 말해주고 있음(deque reference)