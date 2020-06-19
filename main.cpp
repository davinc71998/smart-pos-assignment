#include <iostream>

using namespace std;

#include "Food.h"
#include "Manager.h"

int Food::money = 0; // 가격
int Manager::total = 0;

int main()
{
	Food* pArr = new Food[100];
	Manager mgr1;

	
	int button,i,cnt,catecnt,target,check = 1,pass,selcate,selfood,selpur;
	int sum=0, foodcnt,foodno,cash,cashsum=0;
	int  no,price, category;
	string menu, catename;
	pArr[0].regimenu(1, 1, 3500, "치즈버거", "음식류");
	pArr[1].regimenu(2, 1, 3200, "치킨버거", "음식류");
	pArr[2].regimenu(3, 1, 3800, "불고기버거", "음식류");
	pArr[3].regimenu(4, 2, 1000, "사이다", "음료");
	pArr[4].regimenu(5, 2, 1000, "콜라", "음료");
	pArr[5].regimenu(6, 3, 1300, "감자튀김", "사이드 메뉴");
	pArr[6].regimenu(7, 3, 1500, "해시브라운", "사이드 메뉴");
	pArr[7].regimenu(8, 3, 600, "콘샐러드", "사이드 메뉴");
	pArr[8].regimenu(9, 4, 1300, "라면", "기타");
	pArr[9].regimenu(10, 4, 1300, "짜파게티", "기타");


	cnt = 10;
	catecnt = 4;
	
	while(true)
	{ 
		cout << "1.사용자 메뉴 2.사업자 메뉴 3.시스템 종료" << endl;
		cout << ">>";
		cin >> button;
		if (button == 1) // 사용자 s
		{
			while(true)
			{
				button = 0;
				cout << "1.음식선택 2.결제 3.돌아가기";
				cout << ">> ";
				cin >> button;
				if (button == 1) // 음식 선택 s
				{
					while (true)
					{
						for (i = 0; i < cnt; i++)
						{
							if (pArr[i].reshowcate() == check)
							{
								pArr[i].showcate();
								cout << "  ";
								check++;
							}
						} //카테고리 출력
						cout << endl;
						cout << "접근할 카테고리를 선택하시오 " << endl;
						cout << ">> ";
						cin >> selcate;

						for (i = 0; i < cnt; i++)
						{
							if (pArr[i].reshowcate() == selcate)
							{
								pArr[i].showcatemenu();
							}
						} // 카테고리 선택
						cout << "구매할 메뉴의 번호와 개수를 입력해주세요 " << endl;
						cout << "메뉴번호" << endl;
						cout << ">> ";
						cin >> foodno;
						cout << "개수" << endl;
						cout << ">> ";
						cin >> foodcnt;

						if (pArr[foodno - 1].reshowcate() != selcate)
						{
							cout << "카테고리에 등록되지않은 음식입니다." << endl;
						} 

						else
						{
							pArr[0].money += (pArr[foodno - 1].reshowprice() * foodcnt);
						}

						cout << "1.추가로 구매 2.목록 취소/초기화 , 3.구매 확정" << endl;
						cout << ">> ";
						cin >> selfood;
						if (selfood == 2)
						{
							cout << "이전까지의 목록을 모두 초기화/취소 시킵니다." << endl;
							pArr[0].money = 0;
						}
						else if (selfood == 3)
						{
							cout << "구매를 확정하고 이전메뉴로 넘어갑니다." << endl;
							break;
						}
						check = 1;
					}

				}//음식선택 e
				else if (button == 2) // 결제 s
				{
					if (pArr[0].money == 0)
					{
						cout << "아무 상품도 선택하지 않았습니다." << endl;
					}
					else
					{
						cout << "총 가격은 : " << pArr[0].money << " 입니다. ";

						while (true)
						{
							cout << "1.현금결제 2.카드결제 ";
							cout << ">> ";
							cin >> selpur;
							if (selpur == 1)
							{
								while (cashsum < pArr[0].money)
								{
									cout << "현금을 넣으십시오 " << endl;
									cout << ">> ";
									cin >> cash;
									cashsum += cash;
								}
								mgr1.settotal(pArr[0].money);
								pArr[0].cashpay(cashsum);
								pArr[0].moneyreset();
								break;
							}
							//현금결제
							else if (selpur == 2)
							{
								cout << "카드를 인식시켜주십시오 " << endl;;
								pArr[0].cardpay();
								pArr[0].moneyreset();
							}
							//카드결제
							else
							{
								cout << "잘못된 접근입니다." << endl;
							}
							//잘못된접근
						}
						cout << "결제 완료" << endl;
					}
				}//r결제 e



				else if (button == 3)
				{
					cout << "이전 메뉴로 돌아갑니다." << endl;
					break;
				}//이전 메뉴

				else 
				{
					cout << "잘못된 접근입니다." << endl;
				} // 잘못된 접근
			} // 사용자 e
		}
		else if(button == 2) // 관리자 s
		{
			if(mgr1.showpass() == 0) // 비번 검증
			{
				cout << "비밀번호가 등록되어있지 않습니다 비밀번호를 등록하시오 "<< endl;
				cout << ">> ";
				cin >> pass;
				mgr1.setpass(pass);
			}
			cout << "비밀번호를 입력하시오 " << endl;
			cout << ">> ";
			cin >> pass;

			if (mgr1.showpass() == pass)
			{
				button = 0;
				while (true)
				{
					cout << " 1.메뉴 등록 " << " 2.카테고리 수정"<< " 3.메뉴 변경 "<< " 4.메뉴 삭제 "<< " 5.비밀번호 변경 "<< " 6.현금 정산 " <<" 7.돌아가기 " <<endl;
					cout << ">> ";
					cin >> button;
					if (button == 1) // 메뉴 등록 s
					{
						cout << "등록할 메뉴명 : " << endl;
						cout << ">> ";
						cin >> menu;
						cout << "등록할 메뉴 가격 : " << endl;
						cout << ">> ";
						cin >> price;
						cout << "등록할 메뉴 카테고리 : " << endl;
						cout << ">> ";
						cin >> category;
						cout << "등록할 메뉴 카테고리명 : " << endl;
						cout << ">> ";
						cin >> catename;
						if(catecnt+1 == category)
						{ 
						pArr[cnt].regimenu(cnt+1, category, price, menu, catename);
						cnt++;
						pArr[cnt - 1].fullmenu();
						catecnt++;
						}
						else if(catecnt >= category)
						{
							for (i = 0; i < cnt; i++)
							{
								if (pArr[i].reshowcate() == category)
								{
									target = i;
									break;
								}
							}
							if (pArr[target].reshowcatename() != catename)
							{
								cout << "카테고리 이름이 맞지않습니다."<<endl;

							}
							else
							{
								pArr[cnt].regimenu(cnt + 1, category, price, menu, catename);
								cnt++;
								pArr[cnt - 1].fullmenu();
							}
						}//catecnt 조건
						else 
						{
							cout << "카테고리는 순서대로 증가해야합니다."<<endl;
						}
					}//메뉴 등록 e

					else if (button == 2) // 카테고리 수정 s
					{
						for (i = 0; i < cnt; i++)
						{
							pArr[i].fullmenu();
						}
						cout << "수정할 카테고리 번호는 ? ";
						cout << ">> ";
						cin >> category;
						cout << "수정할 카테고리 이름은 ?  ";
						cout << ">> ";
						cin >> catename;
						if (category > catecnt) {
							cout << "존재하지않는 카테고리입니다." << endl;
						}
						else
						{
							for (i = 0; i < cnt; i++)
							{
								if(pArr[i].reshowcate() == category)
								{
									pArr[i].setcate(i+1,category,catename);
								}
							}
						}
					}//카테고리 수정 e

					else if (button == 3) // 메뉴 수정 s
					{
						for (i = 0; i < cnt; i++)
						{
							pArr[i].fullmenu();
						}
						cout << "변경할 메뉴 번호는 ? ";
						cout << ">> ";
						cin >> no;
						cout << "변경할 메뉴명은 ? : " << endl;
						cout << ">> ";
						cin >> menu;
						cout << "변경할 메뉴 가격은 ?  ";
						cout << ">> ";
						cin >> price;
						cout << "변경할 카테고리 번호는 ? ";
						cout << ">> ";
						cin >> category;
						cout << "변경할 카테고리 이름은 ? ";
						cout << ">> ";
						cin >> catename;
						if (no > cnt)
						{
							cout << "존재하지않는 메뉴입니다." << endl;
						}
						else
						{ // else 시작
							if (catecnt+1 == category)
							{
								pArr[no-1].regimenu(no, category, price, menu, catename);
								pArr[no-1].fullmenu();
								catecnt++;
							}
							else if (catecnt >= category)
							{
								for (i = 0; i < cnt; i++)
								{
									if (pArr[i].reshowcate() == category)
									{
										target = i;
										break;
									}
								}
								if (pArr[target].reshowcatename() != catename)
								{
									cout << "카테고리 이름이 맞지않습니다." << endl;

								}
								else
								{
									pArr[no-1].regimenu(no, category, price, menu, catename);
									pArr[no-1].fullmenu();
								}
							}//catecnt 조건

						}
					} // 메뉴 수정 e

					else if (button == 4) // 메뉴 삭제 s
					{
						for (i = 0; i < cnt; i++)
						{
							pArr[i].fullmenu();
						}
						cout << "삭제할 메뉴 번호는 ? " << endl;
						cout << ">> ";
						cin >> no;
						if (no > cnt)
						{
							cout << "존재하지않는 메뉴입니다."<<endl;
						}
						else{
							for (i = no-1; i < cnt - 1; i++)
							{
								pArr[i].regimenu(pArr[i+1].reshowno()-1,pArr[i+1].reshowcate(),pArr[i+1].reshowprice(),pArr[i+1].reshowmenu(), pArr[i + 1].reshowcatename());
							}
							pArr[cnt].regimenu(0,0,0,"미정","미정카테고리");
							cnt--;
						}
					} //메뉴 삭제 e

					else if (button == 5) //비번 변경 s
					{
						cout << "변경할 비밀번호를 입력하시오 : " << endl;
						cout << ">> ";
						cin >> pass;
						mgr1.setpass(pass);
					} //비번 변경 e

					else if (button == 6) //현금 정산 s
					{
						if (mgr1.total == 0)
						{
							cout << "현금이 없습니다." << endl;
						}
						else{
							cout << "현금 총합 : " << mgr1.total << " 입니다. 현금정산을 진행합니다."<<endl;
							cout << "현금을 받으십시오." << endl;
							mgr1.cashsettle();
							cout << "현금 총합 : " << mgr1.total << " 입니다. 현금정산을 진행합니다." << endl;
						}
					} //현금 정산 e

					else if (button == 7)
					{
						break;
					} //이전메뉴


					else
					{
						cout << "잘못된 접근입니다."<<endl;
					}// 잘못된 접근

				}
			}
			else
			{
				cout << "비밀번호가 맞지않습니다." << endl;
			}
		
		} //관리자 e

		else if(button == 3)
		{
			cout << "시스템을 종료합니다."<<endl;
			break;
		} // 프로그램 종료

		else 
		{
			cout << "허용되지 않은 접근입니다.";
		} // 잘못된 접근
	
	}
	delete[] pArr;// 배열반환
}