#pragma once  
class AMonster  
{  
public: // Change access specifier to protected to allow access in derived classes  
   AMonster();  
   virtual ~AMonster();  
   
   virtual void move();

};
//virtual �̶� ������ �ִ� �Լ������� �װ� �ڽ��� �ڱⲬ�� ����Ҽ� �ֵ��� ���ִ°� �θ𿡴� virtural�����ָ�� 
//virtual�� ������ �ϸ� �迭������ �Լ��� ������ 