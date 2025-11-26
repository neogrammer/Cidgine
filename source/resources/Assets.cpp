#include <resources/Assets.hpp>
#include <resources/ResourceManager.hpp>


ResourceManager<sf::Texture, int> Assets::textures = {};
ResourceManager<sf::Font, int> Assets::fonts = {};
ResourceManager<sf::Music, int> Assets::music = {};
ResourceManager<sf::SoundBuffer, int> Assets::sounds = {};

//
//std::map<std::pair<AnimType, std::string>, std::variant<PlayerState, GoblinState> > Cfg::animStateLookup = {
//	{ std::pair{AnimType::Player,"idleRt"}, PlayerState::Idle },
//	{ std::pair{AnimType::Player,"runRt"}, PlayerState::Running },
//	{ std::pair{AnimType::Player,"attackRt"}, PlayerState::Attacking },
//	{ std::pair{AnimType::Player,"deathRt"}, PlayerState::Dying },
//	{ std::pair{AnimType::Player,"hurtRt"}, PlayerState::Damaged },
//	{ std::pair{AnimType::Player,"jumpRt"}, PlayerState::Jumping },
//	{ std::pair{AnimType::Player,"upToFallRt"}, PlayerState::PeakingJump },
//	{ std::pair{AnimType::Player,"fallRt"}, PlayerState::Falling },
//	{ std::pair{AnimType::Player,"edgeGrabRt"}, PlayerState::GrabbingEdge },
//	{ std::pair{AnimType::Player,"idleEdgeRt"}, PlayerState::HangingFromEdge },
//	{ std::pair{AnimType::Player,"wallSlideRt"}, PlayerState::WallSliding },
//	{ std::pair{AnimType::Player,"crouchRt"}, PlayerState::Crouching },
//	{ std::pair{AnimType::Player,"dashRt"}, PlayerState::Dashing },
//	{ std::pair{AnimType::Player,"dashAttackRt"}, PlayerState::DashAttacking },
//	{ std::pair{AnimType::Player,"slideRt"}, PlayerState::Sliding },
//	{ std::pair{AnimType::Player,"ladderGrabRt"}, PlayerState::LadderClimbing },
//	{ std::pair{AnimType::Player,"idleLt"}, PlayerState::Idle },
//	{ std::pair{AnimType::Player,"runLt"}, PlayerState::Running },
//	{ std::pair{AnimType::Player,"attackLt"}, PlayerState::Attacking },
//	{ std::pair{AnimType::Player,"deathLt"}, PlayerState::Dying },
//	{ std::pair{AnimType::Player,"hurtLt"}, PlayerState::Damaged },
//	{ std::pair{AnimType::Player,"jumpLt"}, PlayerState::Jumping },
//	{ std::pair{AnimType::Player,"upToFallLt"}, PlayerState::PeakingJump },
//	{ std::pair{AnimType::Player,"fallLt"}, PlayerState::Falling },
//	{ std::pair{AnimType::Player,"edgeGrabLt"}, PlayerState::GrabbingEdge },
//	{ std::pair{AnimType::Player,"idleEdgeLt"}, PlayerState::HangingFromEdge },
//	{ std::pair{AnimType::Player,"wallSlideLt"}, PlayerState::WallSliding },
//	{ std::pair{AnimType::Player,"crouchLt"}, PlayerState::Crouching },
//	{ std::pair{AnimType::Player,"dashLt"}, PlayerState::Dashing },
//	{ std::pair{AnimType::Player,"dashAttackLt"}, PlayerState::DashAttacking },
//	{ std::pair{AnimType::Player,"slideLt"}, PlayerState::Sliding },
//	{ std::pair{AnimType::Player,"ladderGrabLt"}, PlayerState::LadderClimbing }
//};
//
//std::map<std::pair<std::variant<PlayerState, GoblinState>, bool>, std::string> Cfg::playerStateStringLookup = {
//	{ std::pair(PlayerState::Idle, true), "idleRt"},
//	{ std::pair(PlayerState::Running, true), "runRt"},
//		{ std::pair(PlayerState::Attacking, true), "attackRt"},
//	{ std::pair(PlayerState::Dying, true), "deathRt"},
//		{ std::pair(PlayerState::Damaged, true), "hurtRt"},
//	{ std::pair(PlayerState::Jumping, true), "jumpRt"},
//		{ std::pair(PlayerState::PeakingJump, true), "upToFallRt"},
//	{ std::pair(PlayerState::Falling, true), "fallRt"},
//		{ std::pair(PlayerState::GrabbingEdge, true), "edgeGrabRt"},
//	{ std::pair(PlayerState::HangingFromEdge, true), "idleEdgeRt"},
//		{ std::pair(PlayerState::WallSliding, true), "wallSlideRt"},
//	{ std::pair(PlayerState::Crouching, true), "crouchRt"},
//		{ std::pair(PlayerState::Dashing, true), "dashRt"},
//		{ std::pair(PlayerState::DashAttacking, true), "dashAttackRt"},
//	{ std::pair(PlayerState::Sliding, true), "slideRt"},
//		{ std::pair(PlayerState::LadderClimbing, true), "ladderGrabRt"},
//		{ std::pair(PlayerState::Idle, false), "idleLt"},
//	{ std::pair(PlayerState::Running, false), "runLt"},
//		{ std::pair(PlayerState::Attacking, false), "attackLt"},
//	{ std::pair(PlayerState::Dying, false), "deathLt"},
//		{ std::pair(PlayerState::Damaged, false), "hurtLt"},
//	{ std::pair(PlayerState::Jumping, false), "jumpLt"},
//		{ std::pair(PlayerState::PeakingJump, false), "upToFallLt"},
//	{ std::pair(PlayerState::Falling, false), "fallLt"},
//		{ std::pair(PlayerState::GrabbingEdge, false), "edgeGrabLt"},
//	{ std::pair(PlayerState::HangingFromEdge, false), "idleEdgeLt"},
//		{ std::pair(PlayerState::WallSliding, false), "wallSlideLt"},
//	{ std::pair(PlayerState::Crouching, false), "crouchLt"},
//		{ std::pair(PlayerState::Dashing, false), "dashLt"},
//		{ std::pair(PlayerState::DashAttacking, false), "dashAttackLt"},
//	{ std::pair(PlayerState::Sliding, false), "slideLt"},
//		{ std::pair(PlayerState::LadderClimbing, false), "ladderGrabLt"}
//};
//
//
//
//std::map<std::pair<AnimType, std::string>, std::variant<PlayerState, GoblinState> > Cfg::goblinAnimStateLookup = {
//	{ std::pair{AnimType::Goblin,"idleRt"}, GoblinState::Idle },
//	{ std::pair{AnimType::Goblin,"runRt"}, GoblinState::Running },
//	{ std::pair{AnimType::Goblin,"attackRt"}, GoblinState::Attacking },
//	{ std::pair{AnimType::Goblin,"hurtRt"}, GoblinState::Damaged },
//	{ std::pair{AnimType::Goblin,"deathRt"}, GoblinState::Dying },
//	{ std::pair{AnimType::Goblin,"idleLt"}, GoblinState::Idle },
//	{ std::pair{AnimType::Goblin,"runLt"}, GoblinState::Running },
//	{ std::pair{AnimType::Goblin,"attackLt"}, GoblinState::Attacking },
//	{ std::pair{AnimType::Goblin,"hurtLt"}, GoblinState::Damaged },
//	{ std::pair{AnimType::Goblin,"deathLt"}, GoblinState::Dying }
//};
//
//std::map<std::pair<std::variant<PlayerState, GoblinState>, bool>, std::string> Cfg::goblinStateStringLookup = {
//	{ std::pair(GoblinState::Idle, true), "idleRt"},
//	{ std::pair(GoblinState::Running, true), "runRt"},
//		{ std::pair(GoblinState::Attacking, true), "attackRt"},
//		{ std::pair(GoblinState::Damaged, true), "hurtRt"},
//	{ std::pair(GoblinState::Dying, true), "deathRt"},
//		{ std::pair(GoblinState::Idle, false), "idleLt"},
//	{ std::pair(GoblinState::Running, false), "runLt"},
//		{ std::pair(GoblinState::Attacking, false), "attackLt"},
//		{ std::pair(GoblinState::Damaged, false), "hurtLt"},
//	{ std::pair(GoblinState::Dying, false), "deathLt"},
//};


void Assets::Initialize()
{
	initTextures();
	initFonts();
	initMusic();
	initSounds();
}

void Assets::initMusic()
{
	music.load((int)Assets::Music::Invariant, "assets/music/music_retro1.mp3");

}

void Assets::initSounds()
{

	sounds.load((int)Assets::Sounds::Invariant, "assets/sounds/pew.mp3");

}

void Assets::initTextures()
{
	
	textures.load((int)Assets::Textures::Invariant, "assets/textures/invariant.png");
	textures.load((int)Assets::Textures::Tileset1, "assets/textures/tilesets/tileset1.png");
	textures.load((int)Assets::Textures::Tileset_Grass, "assets/textures/tilesets/zelda_more.png");
	textures.load((int)Assets::Textures::IsoTileset_Basic, "assets/textures/tilesets/blocksTileSheet.png");




}

void Assets::initFonts()
{
	
	fonts.load((int)Assets::Fonts::Invariant, "assets/fonts/bubbly.ttf");	
}