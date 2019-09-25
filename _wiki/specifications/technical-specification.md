# Technical Specification

# Systems

## General

We will require some systems to manage the overall experience:

* ScoreSystem
* SpawnSystem
* AreaControlSystem
* GameSystem
** ExperienceSystem
** LootSystem
** ShipSystem
** SkillSystem

## Player Control

Create some components:

* PlayerInputComponent
* PlayerCameraComponent
* ShipComponent
* ShipManagementComponent
** add / remove shields
** add / remove upgrades
** manage damage

## Projectiles

The most common projectiles are:

* ProjectileComponent
** PlasmaComponent - visible energy mass moving in a straight line - may cause an effect on collision
** LaserComponent - visible energy in a beam emitting straight ahead - may cause an effect only at point of collision
** MissileComponent - potentionally guided payload - may trigger early, might cause splash damage and various effects

Need to research other possible projectiles.