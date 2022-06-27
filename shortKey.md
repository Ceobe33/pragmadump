## operator visual mode
### view

Use `ctrl u` and `ctrl d` to scrolling the screen by half increments.
Use `ctrl f` and `ctrl b` to scrolling the full screen.

move cursor to the top,middle,bottom of screen is `H, M, L`
- **u**p
- **d**own
- **f**orward
- **b**ack
- **H**ome
- **M**iddle
- **L**ast

todo move the cusor to the begin of line

### visual line mode
`shift + v`	// switch to the visual line mode
`shift` + `<` or `>`	// forward or backward tuckunder

### visual block mode
`ctrl + v`	// switch to the visual block mode

## about directory

``` C++
cd .. 		// go back to the parent directory
cd dicName	// into the dic
cd dicName/name	

```
## about file
rm -rf xxx.swp	// remove the file which is insert name
		// mausally that file is because ctrl+zz 
`gg`		// jump head line of file
`G`		// jump bottom line of file

- insert
`I`		// quickly jump front of line and insert
`A`		// quickly jump end of line and insert

### deleting
- Use `dw` to detele word, the cursor position is important.
If the cusor is in the middle of word, there will delete the cursor to word end.
- Use `diw` to delete whole word from middle[or in word].
- Use `dt<char>` to delete to character. Deletes from your cursor to the specified character.

## Editor

- Mac
	+ Xcode 13


