#pragma once  
class AMonster  
{  
public: // Change access specifier to protected to allow access in derived classes  
   AMonster();  
   virtual ~AMonster();  
   
   virtual void move();

};
//virtual 이란 나한태 있는 함수이지만 그걸 자식이 자기껄로 사용할수 있도록 해주는거 부모에는 virtural만써주면댐 
//virtual로 선언을 하면 배열식으로 함수를 저장함 