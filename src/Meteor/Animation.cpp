#include "stdafx.h"
#include "Animation.h"
#include "Sprite.h"


// ----------------------------------------------------------------
//	Constructor
// ----------------------------------------------------------------
CAnimation::CAnimation( std::string key )
	: m_AnimationKey( key )
	, m_FrameNumber( 0 )
	, m_FpsNumber( 0 )
	, m_ElapsedTime( 0 )
{
}

// ----------------------------------------------------------------
//	Destructor
// ----------------------------------------------------------------
CAnimation::~CAnimation()
{
	for ( auto sprite : m_Sprites )
		delete sprite;
	m_Sprites.clear();
}

// ----------------------------------------------------------------
//	SetSpeed
// ----------------------------------------------------------------
void CAnimation::SetSpeed( int fps )
{
	m_FpsNumber = fps;
}

// ----------------------------------------------------------------
//	LoadSprite
// ----------------------------------------------------------------
bool CAnimation::LoadSprite()
{
	// TODO:
	//	vector<Sprite &> sprites = ResourceManager::GetInstance().GetSprite( m_AnimationKey );

	if( m_AnimationKey == "CHARACTOR_WALK_LEFT" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_LEFT_03.png" ) );
	}

	if( m_AnimationKey == "CHARACTOR_WALK_RIGHT" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_RIGHT_03.png" ) );
	}

	if( m_AnimationKey == "CHARACTOR_WALK_UP" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_UP_03.png" ) );
	}

	if( m_AnimationKey == "CHARACTOR_WALK_DOWN" )
	{
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_01.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_02.png" ) );
		m_Sprites.push_back( CSprite::Create( L"CHARACTOR_WALK_DOWN_03.png" ) );
	}

	return true;
}

// ----------------------------------------------------------------
//	Update
// ----------------------------------------------------------------
bool CAnimation::Update( float deltaTime )
{
	if( m_FpsNumber == 0 )
		return true;

	m_ElapsedTime += deltaTime;

	if( m_ElapsedTime >= float( 1000.0f / m_FpsNumber ) )
	{
		++m_FrameNumber;
		m_ElapsedTime = 0;
	}
	
	if( m_FrameNumber >= m_Sprites.size() )
		m_FrameNumber = 0;

	return true;
}

// ----------------------------------------------------------------
//	Render
// ----------------------------------------------------------------
bool CAnimation::Render()
{
	if( m_FpsNumber == 0 )
	{
		m_Sprites[0]->Render();
		return true;
	}

	m_Sprites[m_FrameNumber]->Render();

	return true;
}
