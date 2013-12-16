import bpy


bpy.data.objects['Montagne'].location[0] = -17.81080
bpy.data.objects['Montagne'].location[1] = 0.34493

bpy.context.object["gridPositionX"] = 1
bpy.context.object["gridPositionY"] = 1
bpy.data.scenes["SceneMontagne"].render.filepath = "//../force-brute/test/proto/bateau/montage/"
bpy.data.scenes["SceneMontagne"].frame_end =  15
bpy.context.object["currentFrame"] = 1
bpy.data.scenes["SceneMontagne"].render.filepath = "//../force-brute/test/proto/bateau/montage/" + str(bpy.context.object["gridPositionX"]) + "_" + str(bpy.context.object["gridPositionY"]) + "_" 

def statscall(context):
    #print("-- ", bpy.context.object["mystrength"])
    #bpy.context.object["mystrength"] = bpy.context.object["mystrength"] - 0.005
    #bpy.context.object["mystrength"] = bpy.context.object["mystrength"] - 0.00075
    #bpy.data.objects['PlanEau'].modifiers['Displace'].strength = bpy.context.object["mystrength"]
    
    bpy.data.scenes["SceneMontagne"].frame_current = bpy.context.object["currentFrame"]
    bpy.context.object["currentFrame"] = (bpy.context.object["currentFrame"] + 1) % 15
    print(" -- frame -- ", bpy.context.object["currentFrame"])
    if bpy.context.object["currentFrame"]  % 15 == 0:
        if bpy.data.objects['Montagne'].location[0] >= -0.26315:
            bpy.data.objects['Montagne'].location[0] = bpy.data.objects['Montagne'].location[0] + 0.64827
            bpy.context.object["gridPositionX"] = bpy.context.object["gridPositionX"] + 1
            print(" -- LOOP #", bpy.context.object["gridPosition"])
            bpy.data.scenes["SceneMontagne"].render.filepath = "//../force-brute/test/proto/bateau/montage/" + str(bpy.context.object["gridPositionX"]) + "_" + str(bpy.context.object["gridPositionY"]) + "_"    
            renderingLoop()
        else:
            if bpy.data.objects['Montagne'].location[1] >= -2.94056:
                bpy.data.objects['Montagne'].location[0] = -17.81080
                bpy.data.objects['Montagne'].location[1] = bpy.data.objects['Montagne'].location[1] - 0.6607
                bpy.context.object["gridPositionY"] = bpy.context.object["gridPositionY"] + 1
                bpy.data.scenes["SceneMontagne"].render.filepath = "//../force-brute/test/proto/bateau/montage/" + str(bpy.context.object["gridPositionX"]) + "_" + str(bpy.context.object["gridPositionY"]) + "_"
                renderingLoop()
            
        
    
def renderingLoop():
    bpy.context.object["currentFrame"] = 0
    bpy.app.handlers.render_stats.clear()
    bpy.app.handlers.render_stats.append(statscall)
    bpy.ops.render.render(animation=True, write_still=True)
    
    
    
    
renderingLoop()