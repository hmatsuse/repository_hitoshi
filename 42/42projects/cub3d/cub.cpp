// / *
// Copyright（c）2004-2019、Lode Vandevenne

// 全著作権所有。

// 以下の条件が満たされている場合に限り、変更の有無にかかわらず、ソースおよびバイナリ形式での再配布および使用が許可されます。

//     *ソースコードの再配布では、上記の著作権表示、この条件のリスト、および次の免責事項を保持する必要があります。
//     *バイナリ形式の再配布では、上記の著作権表示、この条件のリスト、および次の免責事項を、配布物とともに提供されるドキュメントおよび/またはその他の資料に複製する必要があります。

// このソフトウェアは著作権者および寄稿者によって提供されます
// 「現状有姿」および明示または黙示の保証を含むが、
// に限定され、商品性および適合性に関する黙示の保証
// 特定の目的は否認されます。いかなる場合も著作権者または
// 寄稿者は、直接的、間接的、偶発的、特別、
// 例示的または結果的損害（これに限定されないが、
// 代替商品またはサービスの調達; 使用の喪失、データ、または
// 利益; またはビジネスの中断）原因となることはありません。
// 責任、契約、厳格責任、または不法行為（含む）
// 過失またはそれ以外の場合）これを使用することでいかなる方法でも発生する
// そのような損害の可能性について知らされていたとしても、ソフトウェア。
// * /

#include <cmath>
#include <string.h>
#include <vector>
#include <iostream>

#include "quickcg.h"
// 名前空間QuickCGを使用します。

// / *
// g ++ * .cpp -lSDL -O3 -W -Wall -ansi -pedantic
// g ++ * .cpp -lSDL
// * /

//ここにサンプルコードを配置します：

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

int worldMap [mapWidth] [mapHeight] =
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1}、
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1}、
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,0​​,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,0​​,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,0​​,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,0​​,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,0​​,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}、
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int main（int / * argc * /、char * / * argv * / []）
{
  double posX = 22、posY = 12; // xとyの開始位置
  double dirX = -1、dirY = 0; //初期方向ベクトル
  double planeX = 0、planeY = 0.66; //カメラプレーンの2dレイキャスターバージョン

  ダブルタイム= 0; //現在のフレームの時間
  double oldTime = 0; //前のフレームの時間

  screen（screenWidth、screenHeight、0、 "レイキャスター"）;
  while（！done（））
  {
    for（int x = 0; x <w; x ++）
    {
      //光線の位置と方向を計算します
      double cameraX = 2 * x /（double）w-1; //カメラ空間のx座標
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //マップのどのボックスにいるか
      int mapX = int（posX）;
      int mapY = int（posY）;

      //現在の位置から次のxまたはy側までの光線の長さ
      double sideDistX;
      double sideDistY;

       // 1つのxまたはy側から次のxまたはy側までの光線の長さ
      ダブルdeltaDistX = std :: abs（1 / rayDirX）;
      ダブルdeltaDistY = std :: abs（1 / rayDirY）;
      double perpWallDist;

      // xまたはy方向に進む方向（+1または-1）
      int stepX;
      int stepY;

      int hit = 0; //壁に当たりましたか？
      int側。// NSまたはEWの壁にヒットしましたか？
      //ステップと最初のsideDistを計算します
      if（rayDirX <0）
      {
        stepX = -1;
        sideDistX =（posX-mapX）* deltaDistX;
      }
      そうしないと
      {
        stepX = 1;
        sideDistX =（mapX + 1.0-posX）* deltaDistX;
      }
      if（rayDirY <0）
      {
        stepY = -1;
        sideDistY =（posY-mapY）* deltaDistY;
      }
      そうしないと
      {
        stepY = 1;
        sideDistY =（mapY + 1.0-posY）* deltaDistY;
      }
      // DDAを実行する
      while（hit == 0）
      {
        //次のマップの正方形にジャンプ、またはx方向、またはy方向
        if（sideDistX <sideDistY）
        {
          sideDistX + = deltaDistX;
          mapX + = stepX;
          サイド= 0;
        }
        そうしないと
        {
          sideDistY + = deltaDistY;
          mapY + = stepY;
          サイド= 1;
        }
        //光線が壁に当たっているかどうかを確認します
        if（worldMap [mapX] [mapY]> 0）ヒット= 1;
      }
      //カメラ方向に投影された距離を計算します（ユークリッド距離は魚眼効果を与えます！）
      if（side == 0）perpWallDist =（mapX-posX +（1-stepX）/ 2）/ rayDirX;
      else perpWallDist =（mapY-posY +（1-stepY）/ 2）/ rayDirY;

      //画面に描画する線の高さを計算します
      int lineHeight =（int）（h / perpWallDist）;

      //現在のストライプを埋めるために最低と最高のピクセルを計算します
      int drawStart = -lineHeight / 2 + h / 2;
      if（drawStart <0）drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if（drawEnd> = h）drawEnd = h-1;

      //壁の色を選択
      ColorRGBカラー。
      スイッチ（worldMap [mapX] [mapY]）
      {
        ケース1：色= RGB_Red; ブレーク; //赤
        ケース2：色= RGB_Green; ブレーク; //緑
        ケース3：色= RGB_Blue; ブレーク; //青い
        ケース4：color = RGB_White; ブレーク; //白い
        デフォルト：color = RGB_Yellow; ブレーク; //黄
      }

      // x側とy側に異なる明るさを与える
      if（side == 1）{color = color / 2;}

      //ストライプのピクセルを垂直線として描画します
      verLine（x、drawStart、drawEnd、color）;
    }
    //入力とFPSカウンターのタイミング
    oldTime =時間;
    時間= getTicks（）;
    double frameTime =（time-oldTime）/ 1000.0; // frameTimeは、このフレームにかかった時間（秒単位）です
    print（1.0 / frameTime）; // FPSカウンター
    redraw（）;
    cls（）;

    //速度修飾子
    double moveSpeed = frameTime * 5.0; //定数値は平方/秒です
    double rotSpeed = frameTime * 3.0; //定数値はラジアン/秒です
    readKeys（）;
    //目の前に壁がない場合は前方に移動します
    if（keyDown（SDLK_UP））
    {
      if（worldMap [int（posX + dirX * moveSpeed）] [int（posY）] == false）posX + = dirX * moveSpeed;
      if（worldMap [int（posX）] [int（posY + dirY * moveSpeed）] == false）posY + = dirY * moveSpeed;
    }
    //後ろに壁がない場合は後方に移動します
    if（keyDown（SDLK_DOWN））
    {
      if（worldMap [int（posX-dirX * moveSpeed）] [int（posY）] == false）posX-= dirX * moveSpeed;
      if（worldMap [int（posX）] [int（posY-dirY * moveSpeed）] == false）posY-= dirY * moveSpeed;
    }
    //右に回転
    if（keyDown（SDLK_RIGHT））
    {
      //カメラの方向とカメラ平面の両方を回転させる必要があります
      double oldDirX = dirX;
      dirX = dirX * cos（-rotSpeed）-dirY * sin（-rotSpeed）;
      dirY = oldDirX * sin（-rotSpeed）+ dirY * cos（-rotSpeed）;
      double oldPlaneX = planeX;
      平面X =平面X * cos（-rotSpeed）-平面Y * sin（-rotSpeed）;
      planeY = oldPlaneX * sin（-rotSpeed）+ planeY * cos（-rotSpeed）;
    }
    //左に回転
    if（keyDown（SDLK_LEFT））
    {
      //カメラの方向とカメラ平面の両方を回転させる必要があります
      double oldDirX = dirX;
      dirX = dirX * cos（rotSpeed）-dirY * sin（rotSpeed）;
      dirY = oldDirX * sin（rotSpeed）+ dirY * cos（rotSpeed）;
      double oldPlaneX = planeX;
      平面X =平面X * cos（rotSpeed）-平面Y * sin（回転速度）;
      planeY = oldPlaneX * sin（rotSpeed）+ planeY * cos（rotSpeed）;
    }
  }
}