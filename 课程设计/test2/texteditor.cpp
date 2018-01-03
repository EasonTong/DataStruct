#include"texteditor.h"  
void showInstructions(){  
	cout<<"*************�����ı��༭��***************\n";  
	cout<<"ѡ���������ֽ����ı��༭����ʹ��Ӣ�����뷨"<<endl;  
	cout<<"0.��ȡ������Ϣ"<<endl;  
	cout<<"1.��ȡ�ĵ�����"<<endl;  
	cout<<"2.�����ĵ�����"<<endl;  
	cout<<"3.��ʾȫ��"<<endl;  
	cout<<"4.�ƶ����λ��"<<endl;  
	cout<<"5.�ڹ�괦�������"<<endl;  
	cout<<"6.���ĵ�����������"<<endl;  
	cout<<"7.ͳ����������"<<endl;  
	cout<<"8.�����ı����ֵ�λ��"<<endl;  
	cout<<"9.ɾ���ı�"<<endl;  
	cout<<"10.�����ļ�"<<endl;  
	cout<<"11.�˳�ϵͳ"<<endl;  
	cout<<"******************************************"<<endl;  
}  
void getChoice(){  
	TextEditor editor;  
	while(1)  
	{  
		cout<<"\n";  
		cout<<"��ѡ��(0.��ʾ����)��";  
		int n;  
		cin>>n;  
		if(n==11) break;  
		switch(n)  
		{  
		case 0:{  
			showInstructions();  
			break;  
			   }  
		case 1:{  
			cout<<"�ĵ�����Ϊ��"<<editor.getName()<<endl;  
			break;  
			   }  
		case 2:{  
			string s;  
			cout<<"������ �µ��ĵ�����: ";  
			cin>>s;  
			editor.setName(s);  
			cout<<"���óɹ�"<<endl;  
			break;  
			   }  
		case 3:{  
			cout<<editor;  
			int line,pos;  
			editor.getCursor(&line,&pos);  
			cout<<"���Ŀǰ������Ϊ��"<<line<<" ƫ����Ϊ��"<<pos<<endl;  
			break;  
			   }  
		case 4:{  
			int line,pos;  
			editor.getCursor(&line,&pos);  
			cout<<"���Ŀǰ������Ϊ��"<<line<<" ƫ����Ϊ��"<<pos<<endl;  
			cout<<"���Ҫ�ƶ�������:";  
			cin>>line;  
			cout<<"�������һ�е�λ��:";  
			cin>>pos;  
			editor.setCursor(line,pos);  
			break;  
			   }  
		case 5:{  
			cout<<editor;  
			int line,pos;  
			editor.getCursor(&line,&pos);  
			cout<<"���Ŀǰ������Ϊ��"<<line<<" ƫ����Ϊ��"<<pos<<endl;  
			string text;  
			cout<<"��������Ҫд�������(Ӣ��)��"<<endl;  
			cin>>editor;  
			break;  
			   }  
		case 6:{  
			cout<<"������Ҫ��ӵ����֣�"<<endl;  
			string text;  
			char s[100];  
			getchar();  
			gets(s);  
			text = s;  
			editor.addText(text);  
			while(1){  
				cout<<"��������(Y �� N)��";  
				string c;  
				cin>>c;  
				if(c[0]!='Y'&&c[0]!='y') break;  
				getchar();  
				gets(s);  
				text = s;  
				editor.addText(text);  
			}  
			break;  
			   }  
		case 7:{  
			int total,space,num,quot,letter;  
			editor.wordState(&total,&letter,&num,&space,&quot);  
			cout<<"ȫ������Ϊ��"<<total<<endl;  
			cout<<"ȫ����ĸ��Ϊ��"<<letter<<endl;  
			cout<<"ȫ��������Ϊ��"<<num<<endl;  
			cout<<"ȫ�ı����Ϊ��"<<quot<<endl;  
			cout<<"ȫ�Ŀո���Ϊ��"<<space<<endl;  
			break;  
			   }  
		case 8:{  
			cout<<"������Ҫ���ҵ��ı�:"<<endl;  
			string text;  
			char s[100];  
			getchar();  
			gets(s);  
			text = s;  
			int line=1,offset=-1;  
			editor.findTextInAll(text,&line,&offset);  
			while(1){  
				if(offset==-1) break;  
				cout<<"�ı��ڵ�"<<line<<"�еĵ�"<<offset<<"��λ��"<<endl;  
				editor.findTextInAll(text,&line,&offset);  
			}  
			break;  
			   }  
		case 9:{  
			cout<<"1.ɾ��һ���ı�"<<endl;  
			cout<<"2.ɾ���ض�λ�õ��ı�"<<endl;  
			int as;  
			cout<<"������ѡ��";  
			cin>>as;  
			if(as==1){  
				cout<<"������Ҫɾ��������:"<<endl;  
				string text;  
				char s[100];  
				getchar();  
				gets(s);  
				text = s;  
				editor.deleteText(text);  
				cout<<"ɾ���ɹ�"<<endl;  
			}else if (as ==2){  
				cout<<"�����кţ�";  
				int line,pos,length;  
				cin>>line;  
				cout<<"\n����λ�ã�";  
				cin>>pos;  
				cout<<"\n���볤�ȣ�";  
				cin>>length;  
				editor.deleteText(line,pos,length);  
				cout<<"ɾ���ɹ�"<<endl;  
			}  

			break;  
			   }  
		case 10:{  
			editor.saveFile();  
			cout<<"�����ı��ɹ���"<<endl;  
			break;  
				}  
		default:  
			cout<<"�������ִ���"<<endl;  
			continue;  
		}  
	}  
}  
int main()  
{  
	showInstructions();  
	getChoice();  
	system("pause");  
	return 0;  
} 