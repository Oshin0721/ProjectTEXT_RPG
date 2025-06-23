#include <iostream>
#include <cstdlib> // rand(), srand()
#include "GameManager.h"
#include "../Character/Character.h"
#include "../item/AttackBoost.h"
#include "../item/HealthPotion.h"
#include "../Monster/Monster.h"


Monster* GameManager::generateMonster(int level)
{
	srand(0); //���� �� �ʱ�ȭ
	int random = rand() % 3;  //������ ���� 3���� ��ⷯ�ؼ� 1,2,3�� ����

	if (random == 0)
	{
		return new Goblin(level);
	}
	else if (random == 1)
	{
		return new Orc(level);
	}
	else if (random == 2)
	{
		return new Troll(level);
	}
	else if (level == 10)
	{
		return new BossMonster(level);
	}
}
void GameManager::battle(Character* player)
{
	Monster* monster = generateMonster(player -> getLevel());  //���� ����
	cout << monster->getName() << " ����" << endl;  //���� ���� �˸�
	
	while (monster->getHealth() == 0 || player->getHealth() == 0) //���� �ý���
	{
		//���� �ְ� �ޱ�
		monster->takeDamage(player->getAttack());  //�÷��̾ �����Ҷ�
		cout << player->getName << "��(��)" << monster << "��(��) �����߽��ϴ�. ü��: " << player->getHealth << endl;

		if (player->getHealth() <= player->maxHealth*0.5)  //������ ��� �ý��� //�ƽ��ｺ�� �����̺��̶� ���� �ȵ�
		{
			HealthPotion->use(Character* player);
		}
		else if (player->getHealth() <= player->maxHealth*0.75)
		{
			Attackboost->use(Character* player);
		};

		if (monster->getHealth() == 0)  //�¸� ����
		{
			cout << monster->getName() << "��(��) �ο򿡼� �¸��ߴ�!" << endl;
			delete monster;   //���� ����
			int gold = 100;
			player->addGold(gold);
			Item* item = monster->dropItem();
			if (item != nullptr)
			{
				player->addItem(item);
			}
			player->addExperience(50);   //������ ���� 50 ������ �ϱ�
			if (player->getExperience(100))  //100�� �Ǹ� ������
			{
				player->levelUp();
			}
			cout << player->getName() << "��(��)" << gold << "���," << item->getName() << "��(��) ȹ���ߴ�." << endl;
			break;
		}
		
		player->takeDamage(monster->getAttack());   //���Ͱ� ������ ��
		cout << monster << "��(��)" << player->getName() << "��(��) �����߽��ϴ�. ü��: " << monster->getHealth() << endl;
		
		if (player->getHealth() == 0)
		{
			cout << "���" << endl;
		};
		
	}
}
void GameManager::displayInventory(Character* player)
{
	for (Item* item : player->getInventory()) //�� �κ��丮 ���� ����� ����
	{
		cout << item ->getName() << endl;
	}
}
void GameManager::visitShop(Character* player)
{
	while (true)
	{
		cout << "������ �Խ��ϴ�." << endl;
		cout << "���� ���:" << player->getGold() << endl;
		cout << "1. ȸ�� ���� ����" << endl;
		cout << "2. ȸ�� ���� �Ǹ�" << endl;
		cout << "3. ���ݷ� ��ȭ ����" << endl;
		cout << "4. ���ݷ� ��ȭ �Ǹ�" << endl;
		cout << "5. ���� ������" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			player->setgold (player->getGold() - HealthPotion->getBuyPrice(20)); //�� ��� ����
			cout << "���� �Ϸ�. ���� ��� " << gold << endl;
			player->addItem(new HealthPotion);
		}
		else if (choice == 2)
		{
			player->setgold (player->getGold() + HealthPotion->getBuyPrice(20)); //�� ��� ����
			cout << "�Ǹ� �Ϸ�. ���� ��� " << gold << endl;
			player->removeItem(HealthPotion);
		}
		else if (choice == 3)
		{
			player->setgold (player->getGold() - AttackBoost->getBuyPrice(30)); //�� ��� ����
			cout << "���� �Ϸ�. ���� ��� " << gold << endl;
			player->addItem(new AttackBoost);
		}
		else if (choice == 4)
		{
			player->setgold (player->getGold() + AttackBoost->getBuyPrice(30)); //�� ��� ����
			cout << "�Ǹ� �Ϸ�. ���� ��� " << gold << endl;
			player->removeItem()Item(AttackBoost);
		}
		else if (choice == 5)
		{
			return false;
		}
	}
}
