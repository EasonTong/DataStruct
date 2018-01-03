#include"texteditor.h"  
void showInstructions(){  
	cout<<"*************简易文本编辑器***************\n";  
	cout<<"选择以下数字进行文本编辑，请使用英文输入法"<<endl;  
	cout<<"0.获取帮助信息"<<endl;  
	cout<<"1.获取文档名字"<<endl;  
	cout<<"2.设置文档名字"<<endl;  
	cout<<"3.显示全文"<<endl;  
	cout<<"4.移动光标位置"<<endl;  
	cout<<"5.在光标处添加文字"<<endl;  
	cout<<"6.在文档最后添加文字"<<endl;  
	cout<<"7.统计文章字数"<<endl;  
	cout<<"8.查找文本出现的位置"<<endl;  
	cout<<"9.删除文本"<<endl;  
	cout<<"10.保存文件"<<endl;  
	cout<<"11.退出系统"<<endl;  
	cout<<"******************************************"<<endl;  
}  
void getChoice(){  
	TextEditor editor;  
	while(1)  
	{  
		cout<<"\n";  
		cout<<"请选择(0.显示帮助)：";  
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
			cout<<"文档名称为："<<editor.getName()<<endl;  
			break;  
			   }  
		case 2:{  
			string s;  
			cout<<"请输入 新的文档名字: ";  
			cin>>s;  
			editor.setName(s);  
			cout<<"设置成功"<<endl;  
			break;  
			   }  
		case 3:{  
			cout<<editor;  
			int line,pos;  
			editor.getCursor(&line,&pos);  
			cout<<"光标目前的行数为："<<line<<" 偏移量为："<<pos<<endl;  
			break;  
			   }  
		case 4:{  
			int line,pos;  
			editor.getCursor(&line,&pos);  
			cout<<"光标目前的行数为："<<line<<" 偏移量为："<<pos<<endl;  
			cout<<"光标要移动的行数:";  
			cin>>line;  
			cout<<"光标在这一行的位置:";  
			cin>>pos;  
			editor.setCursor(line,pos);  
			break;  
			   }  
		case 5:{  
			cout<<editor;  
			int line,pos;  
			editor.getCursor(&line,&pos);  
			cout<<"光标目前的行数为："<<line<<" 偏移量为："<<pos<<endl;  
			string text;  
			cout<<"请输入你要写入的文字(英文)："<<endl;  
			cin>>editor;  
			break;  
			   }  
		case 6:{  
			cout<<"请输入要添加的文字："<<endl;  
			string text;  
			char s[100];  
			getchar();  
			gets(s);  
			text = s;  
			editor.addText(text);  
			while(1){  
				cout<<"继续插入(Y 或 N)：";  
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
			cout<<"全文总数为："<<total<<endl;  
			cout<<"全文字母数为："<<letter<<endl;  
			cout<<"全文数字数为："<<num<<endl;  
			cout<<"全文标点数为："<<quot<<endl;  
			cout<<"全文空格数为："<<space<<endl;  
			break;  
			   }  
		case 8:{  
			cout<<"请输入要查找的文本:"<<endl;  
			string text;  
			char s[100];  
			getchar();  
			gets(s);  
			text = s;  
			int line=1,offset=-1;  
			editor.findTextInAll(text,&line,&offset);  
			while(1){  
				if(offset==-1) break;  
				cout<<"文本在第"<<line<<"行的第"<<offset<<"个位置"<<endl;  
				editor.findTextInAll(text,&line,&offset);  
			}  
			break;  
			   }  
		case 9:{  
			cout<<"1.删除一段文本"<<endl;  
			cout<<"2.删除特定位置的文本"<<endl;  
			int as;  
			cout<<"请输入选择：";  
			cin>>as;  
			if(as==1){  
				cout<<"请输入要删除的文字:"<<endl;  
				string text;  
				char s[100];  
				getchar();  
				gets(s);  
				text = s;  
				editor.deleteText(text);  
				cout<<"删除成功"<<endl;  
			}else if (as ==2){  
				cout<<"输入行号：";  
				int line,pos,length;  
				cin>>line;  
				cout<<"\n输入位置：";  
				cin>>pos;  
				cout<<"\n输入长度：";  
				cin>>length;  
				editor.deleteText(line,pos,length);  
				cout<<"删除成功"<<endl;  
			}  

			break;  
			   }  
		case 10:{  
			editor.saveFile();  
			cout<<"保存文本成功！"<<endl;  
			break;  
				}  
		default:  
			cout<<"输入数字错误"<<endl;  
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