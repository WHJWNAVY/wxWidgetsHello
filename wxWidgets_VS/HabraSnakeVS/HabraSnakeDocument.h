#ifndef _HABRA_SNAKE_DOCUMENT_H
#define _HABRA_SNAKE_DOCUMENT_H

#include <wx/wx.h>
#include <wx/docview.h>
#include <wx/list.h>

/// Список точе?
WX_DECLARE_LIST(wxPoint, wxPointList);

class HabraSnakeDocument : public wxDocument
{
	/// Размер игрового по?
	static wxSize GameFieldSize;
	DECLARE_DYNAMIC_CLASS(HabraSnakeDocument)
	/// "Сегменты" змейки
	wxPointList m_Snake;
	/// Координаты "цели" для змейки
	wxPoint m_Target;
	/// Призна?окончания игры
	bool m_GameOver;
	/// Количество очко?
	unsigned int m_Score;
	/// Инициализировать змейку
	void InitSnake();
	/// Пересоздат?"цель"
	void CreateNewTarget();
	void ProcessNewPoint(wxPoint * newPoint, bool & targetFound);
	/// Проверка, можн?ли переместиться ?указанну?точк?
	bool CanMoveTo(wxPoint & pos);
	/// Проверка, не умерла ли змейка 
	/// Если змейка зохавала кусо?се?, то вс? каюк
	bool IsSnakeDead();
public:
	HabraSnakeDocument();
	/// Возвращает список сегменто?змейки
	const wxPointList & GetSnake() const;
	/// Возвращает координаты "цели"
	const wxPoint & GetTarget() const;
	/// Выполнит?ша?влев?
	bool MoveLeft(bool & targetFound);
	/// Выполнит?ша?ввер?
	bool MoveUp(bool & targetFound);
	/// Выполнит?ша?вправо
	bool MoveRight(bool & targetFound);
	/// Выполнит?ша?вниз
	bool MoveDown(bool & targetFound);
	/// Возвращает призна?завершен? игры
	bool IsGameOver();
	/// Возвращает количество очко?
	unsigned int GetScore();
	/// Возвращает размер игрового по?
	static wxSize GetGameFieldSize();
};

#endif
