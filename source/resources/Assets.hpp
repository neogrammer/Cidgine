#ifndef ASSETS_HPP__
#define ASSETS_HPP__

#include <SFML/Graphics.hpp>
#include <resources/ResourceManager.hpp>
#include <vector>
#include <variant>
#include <utility>
//
//enum class MachineType
//{
//	Player
//};
//
//enum class OriginPtType
//{
//	Center,
//	TL,
//	TR,
//	TopCenter,
//	BottomCenter,
//	BR,
//	BL,
//	RightCenter,
//	LeftCenter
//};
//
//enum class RayDirType
//{
//	Velocity,
//	Target,
//	ReflectedVelocity,
//	ReflectedTarget
//};
//
//enum class AnimDirType
//{
//	Left,
//	Right,
//	Uni,
//	NotSet
//};
//
//enum class TravelDir
//{
//	Horizontal,
//	Vertical,
//	Directed,
//	Scripted,
//	Path,
//	NotSet
//};
//
//enum class ProjectileType
//{
//	Base,
//	BusterBullet
//};
//
//enum class ResolutionDir : int
//{
//	Up,
//	Down,
//	Left,
//	Right,
//	None
//};
//
//enum class SpriteType
//{
//	Player,
//	Projectile,
//	Platform,
//	Enemy,
//	Tile,
//	Basic
//};
//
//enum class CmdType
//{
//	Move,
//	Count
//};
//
//enum class TexType
//{
//	Player,
//	Tile,
//	NotSet
//};
//
//
//enum class GameStateType
//{
//	None,
//	Splash,
//	Title,
//	Play,
//	Gameover,
//	Menu,
//	Pause,
//	StageSelect,
//	StageClearState
//};
//
//enum class GameEvent
//{
//	StoppedRunning,
//	StartedRunning,
//	StartedAttacking,
//	StoppedAttacking,
//	ContinuedAttacking,
//	DamageCooldownEnded,
//	LifeDepleted,
//	Damaged,
//	Jumped,
//	PeakingJump,
//	Fell,
//	GrabbingForLedge,
//	HoldingOntoLedge,
//	StartedToRepel,
//	JumpedOffWall,
//	Crouched,
//	Dashed,
//	StartedDashAttack,
//	ContinuedDashAttack,
//	StoppedDashAttack,
//	Slid,
//	GrabbedOntoLadder,
//	Count
//};
//
//enum class AnimType
//{
//	Player,
//	Goblin,
//	Count
//};
//
//enum class PlayerState
//{
//	Idle,
//	Running,
//	Attacking,
//	Dying,
//	Damaged,
//	Jumping,
//	PeakingJump,
//	Falling,
//	GrabbingEdge,
//	HangingFromEdge,
//	WallSliding,
//	Crouching,
//	Dashing,
//	DashAttacking,
//	Sliding,
//	LadderClimbing,
//	Count
//};
//
//enum class GoblinState
//{
//	Idle,
//	Running,
//	Attacking,
//	Damaged,
//	Dying,
//	Count
//};
//
//enum class Dir
//{
//	Right,
//	Left,
//	Count
//};

struct Assets
{
	Assets() = delete;
	Assets(const Assets&) = delete;
	Assets& operator=(const Assets&) = delete;


	//globals 
	//static sol::state lua; // globals are bad, but we'll use it for simpler implementation
	static void Initialize();

	// Resource Enums 
	enum class Textures : int { IsoTileset_Basic, Tileset_Grass, Tileset1, Invariant, Count };
	enum class Fonts : int {  Invariant, Count };
	enum class Music : int { Invariant, Count };
	enum class Sounds : int { Invariant, Count };


	// resource buckets for each type of resource
	static ResourceManager<sf::Texture, int> textures;
	static ResourceManager<sf::Music, int> music;
	static ResourceManager<sf::SoundBuffer, int> sounds;
	static ResourceManager<sf::Font, int> fonts;

private:
	// initalize the resources for the entire game
	static void initFonts();
	static void initMusic();
	static void initSounds();
	static void initTextures();
};


#endif