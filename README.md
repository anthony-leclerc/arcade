<div class="readme">

  <div class="title">
    <center><h1>Arcade API documentation</h1></center>
  </div>

  <br />

  <div class="intro">
    The Arcade API is a set of tools allowing the user to conceive, create and play arcade-like games, such as Pac-man, Snake or Centipede.
    The goal of this documentation is to help you unterstand the usage basics of the Arcade API, and to give you all the useful tools to create your own games.
    For more infos about the Arcade project, click <a href='https://www.youtube.com/watch?v=dQw4w9WgXcQ'>here</a>.
  </div>

  <br />

  <div class="menu">
    <h2>Summary</h2>
    <ol>
      <li><h4>Description of the API</h4></li>
      <li><h4>Usage rules</h4></li>
    </ol>
  </div>

  <br />

  <div class="Description">
    <h2>Description</h2>
    <br />
    The Arcade API is an architecture template. It is the base of the Arcade project, and allows the user to dynamically load and play games and graphic libraries.
    Thanks to the linking of dynamic libraries, the user can play games and load graphic libraries event at run-time.
    <br />
    There are several rules to respect while using this API, which will be explained in this documentation.
    However, we recommend you to take a look at the "Classes" section of this documentation, to comprehend better what we are going to talk about now.
  </div>

  <br />

  <div class="Rules">
    <h2>Rules</h2>
    <br />
    As you might have seen, this architexture is guite simple. But it must respond to several rules.
    <br />
    The game logic is axed around the cell logic. We call cell logic the fact that positions and graphical actions are calculated thanks to a cell system.
    <br />
    This cell system is a grid pattern where a square is of a given size. The sprites and actions will occur between them, and will not affect the neighbor cells.
    <br />
    Moving responding to the cell logic can't display fluid animations. It reproduces the behavious os the old Arcade games.
    <br />
    <br />
    The ressource files such as images or spritesheets must be situated at the same place as the Arcade project executable.
    <br />
    <br />
    Every method must be created if you want to create your own dynamic library. Here are a few precisions :
    <ul>
      <li>Your context class must contain a IGraphic interface and a IEvents interface. It must have getters to interact with them.</li>
      <li>The context must implement 2 different function prototyped as follows :
	<ul>
	  <li>extern "C" arcade::api::IContext *entry_point();</li>
	  <li>extern "C" void delete_point(arcade::api::IContext *mod);</li>
	</ul>
	entry_point must return a pointer on your new Context, and delete_point must delete it.
	That is how the loader works.
      </li>
      <li>The graphic libs must be in the "./lib" directory</li>
      <li>The game libs must be in the "./games" directory</li>
    </ul>
  </div>

  <br />
  <br />

  Hoping this documentation will help you playing with the Arcade project !

  <br />
  <br />

  <center><h5>Sylvain CHAUGNY - Anthony LECLERC - Hugo BALBAFFIN</h5></center>
</div>
