#ifndef _HABRA_SNAKE_DOCUMENT_H
#define _HABRA_SNAKE_DOCUMENT_H

#include <wx/wx.h>
#include <wx/docview.h>
#include <wx/list.h>

/// ������ ����?
WX_DECLARE_LIST(wxPoint, wxPointList);

class HabraSnakeDocument : public wxDocument
{
	/// ������ �������� ��?
	static wxSize GameFieldSize;
	DECLARE_DYNAMIC_CLASS(HabraSnakeDocument)
	/// "��������" ������
	wxPointList m_Snake;
	/// ���������� "����" ��� ������
	wxPoint m_Target;
	/// ������?��������� ����
	bool m_GameOver;
	/// ���������� ����?
	unsigned int m_Score;
	/// ���������������� ������
	void InitSnake();
	/// ����������?"����"
	void CreateNewTarget();
	void ProcessNewPoint(wxPoint * newPoint, bool & targetFound);
	/// ��������, ����?�� ������������� ?��������?����?
	bool CanMoveTo(wxPoint & pos);
	/// ��������, �� ������ �� ������ 
	/// ���� ������ �������� ����?��?, �� ��? ����
	bool IsSnakeDead();
public:
	HabraSnakeDocument();
	/// ���������� ������ ��������?������
	const wxPointList & GetSnake() const;
	/// ���������� ���������� "����"
	const wxPoint & GetTarget() const;
	/// ��������?��?����?
	bool MoveLeft(bool & targetFound);
	/// ��������?��?����?
	bool MoveUp(bool & targetFound);
	/// ��������?��?������
	bool MoveRight(bool & targetFound);
	/// ��������?��?����
	bool MoveDown(bool & targetFound);
	/// ���������� ������?��������? ����
	bool IsGameOver();
	/// ���������� ���������� ����?
	unsigned int GetScore();
	/// ���������� ������ �������� ��?
	static wxSize GetGameFieldSize();
};

#endif
